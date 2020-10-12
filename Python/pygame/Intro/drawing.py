import pygame, sys
from pygame.locals import *

pygame.init()

DISPLAYSURF = pygame.display.set_mode((500,400), 0, 30)
pygame.display.set_caption('Drawing')

#nastav farby
BLACK = (0,0,0)
WHITE = (255,255,255)
RED = (255,0,0)
GREEN = (0,255,0)
BLUE = (0,0,255)

DISPLAYSURF.fill(WHITE)
#polygon(surface, color, pointlist, width)
pygame.draw.polygon(DISPLAYSURF, GREEN, ((146,0), (291,106), (236,277),(56,277),(0,106)))

#line(surface, color, start_point, end_point, width)
pygame.draw.line(DISPLAYSURF, BLUE, (60,60), (120,60), 4)
pygame.draw.line(DISPLAYSURF, BLUE, (120,60), (60,120))
pygame.draw.line(DISPLAYSURF, BLUE, (60,120), (120,120), 4)

#lines(surface, color, closed, pointlist, width)
# its something between line annd polygon
# it will draw a series of lines from one point to antoher
# but if there is closed = False, there will be not a line
#  from the last point to the first one

#circle(surface, color, center_point, radius, width)
pygame.draw.circle(DISPLAYSURF, BLUE, (300,50), 50, 0)
#ellipse(surface, color, bounding_rectangle, width)
# will draw ellipse inside the rectangle
pygame.draw.ellipse(DISPLAYSURF, RED, (300,250,40,80), 5)
#rect(surface, color, rectangle_tuple, width)
pygame.draw.rect(DISPLAYSURF, RED, (291,106,100,50))

pixObj = pygame.PixelArray(DISPLAYSURF)
pixObj[480][380] = BLACK
pixObj[482][382] = BLACK
pixObj[478][382] = BLACK
pixObj[480][384] = BLACK
del pixObj

#main loop game
while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
    pygame.display.update()
