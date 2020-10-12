import pygame
from pygame.locals import *
import sys
import random

pygame.init()
width, height = 1366, 768

WHITE = (255, 255, 255)
BLACK = (0  , 0  , 0  )

screen = pygame.display.set_mode((width, height))
pygame.display.set_caption('Random Shooter')

running = 1
while running:
    screen.fill(BLACK)
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
    pygame.display.flip()
