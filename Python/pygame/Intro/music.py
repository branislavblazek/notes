import pygame
import sys
from pygame.locals import *

pygame.init()

sound = pygame.mixer.Sound('files/beep.wav')
sound.play()

DISPLAYSURF = pygame.display.set_mode((400,300), 0, 32)
pygame.display.set_caption('Sounds!')



pygame.mixer.music.load('files/TheCivilWars.mp3')
pygame.mixer.music.play(-1, 0.0)

while True:
    for event in pygame.event.get():
        if event.type == MOUSEBUTTONDOWN:
            sound.play()
        elif event.type == KEYDOWN:
            pygame.mixer.music.stop()
        elif event.type == QUIT:
            pygame.quit()
            sys.exit()
