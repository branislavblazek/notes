import tkinter
from random import *#druhy zapis importovania modulov, nemusim potom pisat random.choice ale iba choice
canvas = tkinter.Canvas(width="900", height="500")
canvas.pack()

def rand(m):
    if m == 0:
        return choice(('brown', 'red', 'blue', 'green', 'yellow', 'pink', 'black'))
    elif m == 1:
        return randint(0,100)
    elif m == 2:
        return choice(('Veľká Okružná', 'Pythonova', 'Slepačia', 'Tulipánova'))
def domcek(x,y):
    canvas.create_rectangle(x, y, x+100, y+100, fill=str(rand(0)), outline=str(rand(0)))
    canvas.create_polygon(x, y, x+101, y, x+50, y-50, fill=str(rand(0)), outline=str(rand(0)))
def stromcek(x,y,v):
    canvas.create_rectangle(x+20, y, x+40, y-40-v, fill='brown')
    canvas.create_oval(x, y-v, x+60, y-v-60, fill='green')

def ulica(n):
    nazov = (str(rand(2)))
    for i in range(len(nazov)):
        if i % 2 == 0:
            ang = 0
        elif i % 2 != 0:
            ang = 180
        canvas.create_text(50+i*50,50, text=nazov[i], font='Arial 50', angle=ang)
    for i in range(n):
        domcek(60 + i * 160, 200)
    for i in range(n-1):
        stromcek(160 + i * 160, 350, int(rand(1)))

inpt = int(input('Zadajte počet domčekov:'))
ulica(inpt)

canvas.mainloop()
