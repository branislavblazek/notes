import pygame
import random
import sys
from pygame.locals import *
import time

#nejake konstanty
CONST = {
    'color_intro': (230, 155, 44),
    'color_black': (0,0,0),
    'color_white': (255,255,255),
    'color_gray': (110, 107, 107),
    'color_yellow': (255, 247, 0),
    'color_blue': (0,0,255),
    'color_green': (0,255,0),
    'color_red': (255,0,0),
    'window_width': 700,
    'window_height': 700
}

velkost = 4
velkost_rect = 125
#vytvor mriezku
objekty_pocet = []

pocet_obj = 0

objekty = {'o':0, 'k':0, 't':0, 's':0}
for tvar in objekty:
    pocet = random.randint(2,velkost-1)
    objekty[tvar] = pocet
    pocet_obj += pocet

game = []
for stlpec in range(velkost):
    line = []
    for riadok in range(velkost):
        line.append(0)
    game.append(line)

list_x = list(objekty.keys())
for tt in range(pocet_obj):
    ok = None
    while not ok:
        x = random.randint(0, velkost-1)
        y = random.randint(0, velkost-1)
        if game[x][y] == 0:
            game[x][y] = list_x[tt % velkost]
            ok = True


#initialize
pygame.init()
surface = pygame.display.set_mode((CONST['window_width'], CONST['window_height']), 0, 32)
pygame.display.set_caption('Geomexo')

#intro surface
def intro():
    mainfontObj = pygame.font.Font('freesansbold.ttf', 140)
    mainSurfaceObj = mainfontObj.render('Geomexo', True, CONST['color_black'])
    mainRectObj = mainSurfaceObj.get_rect()
    mainRectObj.center = (350, 350)

    autorFontObj = pygame.font.Font('freesansbold.ttf', 32)
    autorSurfaceObj = autorFontObj.render('Vytvoril Branislav Blazek', True, CONST['color_black'])
    autorRectObj = autorSurfaceObj.get_rect()
    autorRectObj.center = (350, 450)

    while True:
        surface.fill(CONST['color_intro'])
        surface.blit(mainSurfaceObj, mainRectObj)
        surface.blit(autorSurfaceObj, autorRectObj)

        now = pygame.time.get_ticks()
        if now - start >= 5000:
            return

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
        pygame.display.update()

def see_objects():

    while True:
        surface.fill(CONST['color_intro'])
        for y in range(velkost):
            for x in range(velkost):
                pygame.draw.rect(surface, CONST['color_gray'], (x*(velkost_rect+25)+50, y*(velkost_rect+25)+50, velkost_rect, velkost_rect))
                if game[y][x] == 'o':
                    pygame.draw.rect(surface, CONST['color_yellow'], (x*(velkost_rect+25)+50, y*(velkost_rect+25)+75, velkost_rect, velkost_rect-50))
                elif game[y][x] == 'k':
                    pygame.draw.ellipse(surface, CONST['color_red'], (x*(velkost_rect+25)+50, y*(velkost_rect+25)+50, velkost_rect, velkost_rect))
                elif game[y][x] == 't':
                    z_x = x*(velkost_rect+25)+50
                    z_y = y*(velkost_rect+25)+50
                    pygame.draw.polygon(surface, CONST['color_green'], ((z_x, z_y+velkost_rect),(z_x+velkost_rect,z_y+velkost_rect),(z_x+velkost_rect//2,z_y)))
                elif game[y][x] == 's':
                    z_x = x*(velkost_rect+25)+50
                    z_y = y*(velkost_rect+25)+50
                    tretina = velkost_rect // 3
                    pygame.draw.polygon(surface, CONST['color_blue'], ((z_x+tretina, z_y),(z_x+tretina*2,z_y),(z_x+velkost_rect,z_y+velkost_rect//2), (z_x+tretina*2, z_y+velkost_rect), (z_x+tretina, z_y+velkost_rect),(z_x, z_y+velkost_rect//2)))
        now = pygame.time.get_ticks()
        if now - start >= 8000:
            return

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
        pygame.display.update()

def hide_objects():
    what_ask = random.choice(['k', 'o', 's', 't', 'n'])

    if what_ask != 'n':
        odpoved = objekty[what_ask]
    else:
        ostava = velkost * velkost
        for line in game:
            for x in line:
                if x != '0':
                    ostava -= 1
        odpoved = ostava
    print(odpoved)

    clock = pygame.time.Clock()
    input_box = pygame.Rect(275, 650, 150, 50)
    color_inactive = pygame.Color('lightskyblue3')
    color_active = pygame.Color('dodgerblue2')
    color = color_inactive
    active = False
    text = ''
    done = False
    xxx = -1
    spravne = False

    asking = 'kruhov' if what_ask == 'k' else 'obdĺžnikov' if what_ask == 'o' else 'šesťuholníkov' if what_ask == 's' else 'trojuholníkov' if what_ask == "t" else "prázdnych políčkok"
    veta = 'Koľko bolo na obrázku ' + asking + ' ?'
    askFont = pygame.font.Font('freesansbold.ttf', 32)
    askSurafaceObj = askFont.render(veta, True, CONST['color_black'])
    askRect = askSurafaceObj.get_rect()
    askRect.center = (350,350)
    while True:
        surface.fill(CONST['color_intro'])
        for y in range(velkost):
            for x in range(velkost):
                pygame.draw.rect(surface, CONST['color_gray'], (x*(velkost_rect+25)+50, y*(velkost_rect+25)+50, velkost_rect, velkost_rect))
        surface.blit(askSurafaceObj, askRect)
        now = pygame.time.get_ticks()
        if spravne:
            winFont = pygame.font.Font('freesansbold.ttf', 32)
            winSurafaceObj = winFont.render('Vyhral si!', True, CONST['color_black'])
            winRect = winSurafaceObj.get_rect()
            winRect.center = (350,500)
            surface.blit(winSurafaceObj, winRect)
            time.sleep(2)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.MOUSEBUTTONDOWN:
                # If the user clicked on the input_box rect.
                if input_box.collidepoint(event.pos):
                    # Toggle the active variable.
                    active = not active
                else:
                    active = False
                # Change the current color of the input box.
                color = color_active if active else color_inactive
            if event.type == pygame.KEYDOWN:
                if active:
                    if event.key == pygame.K_RETURN:
                        xxx = text
                        spravne = True
                        text = ''
                    elif event.key == pygame.K_BACKSPACE:
                        text = text[:-1]
                    else:
                        text += event.unicode
        txt_surface = askFont.render(text, True, color)
        # Resize the box if the text is too long.
        width = max(200, txt_surface.get_width()+10)
        input_box.w = width
        # Blit the text.
        surface.blit(txt_surface, (input_box.x+5, input_box.y+5))
        # Blit the input_box rect.
        pygame.draw.rect(surface, color, input_box, 2)

        pygame.display.flip()
        clock.tick(30)

        pygame.display.update()

start = pygame.time.get_ticks()
intro()
start = pygame.time.get_ticks()
see_objects()
start = pygame.time.get_ticks()
hide_objects()
