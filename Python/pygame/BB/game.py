import pygame
from pygame.locals import *
import sys
import math
import random

pygame.init()
width, height = 640, 480
keys = [False, False, False, False]#WASD
playerpos = [100,100]
acc = [0,0]#accuracy of the player
arrows = []
badtimer = 100
badtimer1 = 0
badguys = [[640,1000]]
healthvalue = 194
pygame.mixer.init()


screen = pygame.display.set_mode((width, height))

player = pygame.image.load('resources/images/dude.png')
grass = pygame.image.load('resources/images/grass.png')
castle = pygame.image.load('resources/images/castle.png')
arrow = pygame.image.load('resources/images/bullet.png')
badguyimg1 = pygame.image.load('resources/images/badguy.png')
healthbar = pygame.image.load('resources/images/healthbar.png')
health = pygame.image.load('resources/images/health.png')
gameover = pygame.image.load('resources/images/gameover.png')
youwin = pygame.image.load('resources/images/youwin.png')
badguyimg = badguyimg1
hit = pygame.mixer.Sound('resources/audio/explode.wav')
enemy = pygame.mixer.Sound('resources/audio/enemy.wav')
shoot = pygame.mixer.Sound('resources/audio/shoot.wav')
hit.set_volume(0.05)
enemy.set_volume(0.05)
shoot.set_volume(0.05)
pygame.mixer.music.load('resources/audio/moonlight.wav')
pygame.mixer.music.play(-1, 0.0)
pygame.mixer.music.set_volume(0.25)

running = 1
exitcode = 0
while running:
    badtimer -= 1
    screen.fill((0,0,0))
    #6 - draw player
    for x in range(int(width/grass.get_width()+1)):
        for y in range(int(height/grass.get_height()+1)):
            screen.blit(grass, (x*100, y*100))

    for y in range(30,450,105):
        screen.blit(castle, (0, y))
    #6.1 position and rotation
    position = pygame.mouse.get_pos()
    angle = math.atan2(position[1]-(playerpos[1]+32),position[0]-playerpos[0]+26)
    playerrot = pygame.transform.rotate(player, 360-angle*57.29)
    playerpos1 = (playerpos[0]-playerrot.get_rect().width/2, playerpos[1]-playerrot.get_rect().height/2)
    screen.blit(playerrot, playerpos1)
    #6.2 draw arrows
    for bullet in arrows:
        index = 0
        velx = math.cos(bullet[0])*10
        vely = math.sin(bullet[0])*10
        bullet[1] += velx
        bullet[2] += vely
        if bullet[1] <= 64 or bullet[1] > 640 or bullet[2] <= 64 or bullet[2] > 480:
            arrows.pop(index)
        index += 1
        for projectile in arrows:
            arrow1 = pygame.transform.rotate(arrow, 360-projectile[0]*57.29)
            screen.blit(arrow1, (projectile[1], projectile[2]))
    #6.3 badgers
    if badtimer == 0:
        badguys.append([640, random.randint(50,430)])
        badtimer = 100 - (badtimer1*2)
        if badtimer1 >= 35:
            badtimer1 = 35
        else:
            badtimer1 += 5
    index = 0
    for badguy in badguys:
        if badguy[0] <= 64:
            badguys.pop(index)
        badguy[0] -= 7
        #6.3.1 attack castle
        badrect = pygame.Rect(badguyimg.get_rect())
        badrect.top = badguy[1]
        badrect.left = badguy[0]
        if badrect.left < 64:
            hit.play()
            healthvalue -= random.randint(5,20)
            badguys.pop(index)
        #6.3.2 check for collision
        index1 = 0
        for bullet in arrows:
            bullrect = pygame.Rect(arrow.get_rect())
            bullrect.left = bullet[1]
            bullrect.top = bullet[2]
            if badrect.colliderect(bullrect):
                enemy.play()
                acc[0]+=1
                badguys.pop(index)
                arrows.pop(index1)
            index1 += 1
        #6.3.3 next bad guy
        index += 1
    for badguy in badguys:
        screen.blit(badguyimg, badguy)
    #6.4 clock
    font = pygame.font.Font(None, 24)
    min = str(int((90000-pygame.time.get_ticks())/60000))
    sec = str(int((90000-pygame.time.get_ticks())/1000%60))
    survivedtext = font.render(min+":"+sec, True, (0,0,0))
    textRect = survivedtext.get_rect()
    textRect.topright = [635,5]
    screen.blit(survivedtext, textRect)
    #6.5 health
    screen.blit(healthbar, (5,5))
    for health1 in range(healthvalue):
        screen.blit(health, (health1+8, 8))

    pygame.display.flip()

    for event in pygame.event.get():
        if event.type == QUIT:
            sys.exit()
            pygame.quit()
        if event.type == pygame.KEYDOWN:
            if event.key == K_w:
                keys[0] = True
            elif event.key == K_a:
                keys[1] = True
            elif event.key == K_s:
                keys[2] = True
            elif event.key == K_d:
                keys[3] = True
        if event.type == pygame.KEYUP:
            if event.key == K_w:
                keys[0] = False
            elif event.key == K_a:
                keys[1] = False
            elif event.key == K_s:
                keys[2] = False
            elif event.key == K_d:
                keys[3] = False
        if event.type == pygame.MOUSEBUTTONDOWN:
            shoot.play()
            position = pygame.mouse.get_pos()
            acc[1] += 1
            arrows.append([math.atan2(position[1]-(playerpos1[1]+32),position[0]-(playerpos1[0]+26)),playerpos1[0]+32,playerpos1[1]+32])

    if keys[0]:
        playerpos[1] -= 5
    elif keys[2]:
        playerpos[1] += 5
    elif keys[1]:
        playerpos[0] -= 5
    elif keys[3]:
        playerpos[0] += 5

    if pygame.time.get_ticks() >= 90000:
        running = 0
        exitcode = 1
    if healthvalue <= 0:
        running = 0
        exitcode = 0
    if acc[1] != 0:
        accuracy = acc[0]*1.0/acc[1]*100
    else:
        accuracy = 0
#win lose
if exitcode == 0:
    pygame.font.init()
    font = pygame.font.Font(None, 24)
    text = font.render("Accuracy: " + str(accuracy) + "%", True, (255,0,0))
    textRect = text.get_rect()
    textRect.centerx = screen.get_rect().centerx
    textRect.centery = screen.get_rect().centery + 24
    screen.blit(gameover, (0,0))
    screen.blit(text, textRect)
else:
    pygame.font.init()
    font = pygame.font.Font(None, 24)
    text = font.render("Accuracy: "+str(accuracy)+"%", True, (0,255,0))
    textRect = text.get_rect()
    textRect.centerx = screen.get_rect().centerx
    textRect.centery = screen.get_rect().centery+24
    screen.blit(youwin, (0,0))
    screen.blit(text, textRect)
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    pygame.display.flip()