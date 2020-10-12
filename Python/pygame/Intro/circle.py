import pygame, sys
from pygame.locals import *
import math

pygame.init()

#set up the window
screen = pygame.display.set_mode((600, 600), 0, 32)
pygame.display.set_caption('Cat animation')

WHITE = (255,255,255)
catImg = pygame.image.load('files/log.png')
catImg = pygame.transform.scale(catImg, (160, 70))
catx = 300
caty = 300
cat_rect = catImg.get_rect()
cat_rect.center = (catx, caty)
r = 0

while True:
    screen.fill(WHITE)

    screen.blit(catImg, cat_rect)

    aaa = catImg.copy()
    aaa = pygame.transform.rotozoom(aaa, 50, 1)

    for uhol in range(0,360,90):
        #x = catx + r * math.cos(math.radians(uhol))
        #y = catx + r * math.sin(math.radians(uhol))
        rect = aaa.get_rect()
        rect.center = (300,300)
        screen.blit(aaa, rect)

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()

    pygame.display.update()
