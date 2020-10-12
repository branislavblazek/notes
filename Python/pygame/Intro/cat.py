import pygame, sys
from pygame.locals import *
#initalize
pygame.init()

#set sound for cat
meow = pygame.mixer.Sound('files/cat_meow.wav')
#CONST for colors
WHITE = (255, 255, 255)
BLACK = (0  ,   0,   0)
GREEN = (0  , 255,   0)
#CONST for FPS, set fps
FPS = 30
fpsClock = pygame.time.Clock()
#CONST for window size
WIDTH = 600
HEIGHT = 600
#set up values for a cat
# - load image
catImg = pygame.image.load('files/unicorn.png')
# - set starting point
catx = 0
caty = 0
# - set value of what will the cat move
valuex = 5
valuey = 5
# - set values for max x,y where cat could be, image is 125x79
MAX_WIDTH = WIDTH - 150
MAX_HEIGHT = HEIGHT - 150

#set up the window
surface = pygame.display.set_mode((WIDTH, HEIGHT), 0, 32)
pygame.display.set_caption('Hlupy kon!')

#main game loop
while True:
    surface.fill(GREEN)

    catx += valuex
    caty += valuey

    if catx >= MAX_WIDTH or catx < 0:
        meow.play()
        valuex = -valuex
    if caty >= MAX_HEIGHT or caty < 0:
        meow.play()
        valuey = -valuey

    surface.blit(catImg, (catx, caty))

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
    pygame.display.update()
    fpsClock.tick(FPS)
