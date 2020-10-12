import pygame, sys
from pygame.locals import *

pygame.init()

FPS = 30
fpsClock = pygame.time.Clock()

#set up the window
DISPLAYSURF = pygame.display.set_mode((600, 600), 0, 32)
pygame.display.set_caption('Cat animation')

WHITE = (255,255,255)
catImg = pygame.image.load('files/cat.png')
catx = 0
caty = 0
direction = 'right'

while True:
    DISPLAYSURF.fill(WHITE)

    if direction == 'right':
        catx += 5
        if catx == 400-125:
            direction = 'down'
    elif direction == 'down':
        caty += 5
        if caty == 400-80:
            direction = 'left'
    elif direction == 'left':
        catx -= 5
        if catx == 0:
            direction = 'up'
    elif direction == 'up':
        caty -= 5
        if caty == 0:
            direction = 'right'

    DISPLAYSURF.blit(catImg, (catx, caty))

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()

    pygame.display.update()
    fpsClock.tick(FPS)
