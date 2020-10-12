import pygame, sys
from pygame.locals import *
import tempfile
import os
import pkgutil

pygame.init()
DISPLAYSURF = pygame.display.set_mode((400, 300))
pygame.display.set_caption('Hello world!')

'''
six steps to create text

1) create pygame.font.Font obj
2) create surface obj with text drawn on it by calling render function
3) create rect obj from surface, this will have the width and height, top, left = 0
4) changing position of rec
5) blit the surface obj with text onto the Surface obj
6) call update to display text
'''

WHITE = (255,255,255)
GREEN = (0,255,0)
BLUE = (0,0,128)

def load_font(filename, size):
    tmpdir = tempfile.mkdtemp()
    fname = os.path.join(tmpdir, filename)
    try:
        with open(fname, 'wb') as f:
            print(pkgutil.get_data('files', 'verdana.ttf'))
            data = pkgutil.get_data('files', 'verdana.ttf')
            f.write(data)
        font = pygame.font.Font(fname, size)
    finally:
        try:
            os.remove(fname)
            os.rmdir(tmpdir)
        except:
            pass
    return font

fontObj = load_font('verdana.ttf', 32)
textSurfaceObj = fontObj.render('Hello world!', True, GREEN, BLUE)
#True stands for aliasing, when its True, its more beautiful
#color of text, color of bg
textRectObj = textSurfaceObj.get_rect()
textRectObj.center = (200,150)


while True:
    DISPLAYSURF.fill(WHITE)
    DISPLAYSURF.blit(textSurfaceObj, textRectObj)
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
    pygame.display.update()
