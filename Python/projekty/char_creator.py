import tkinter
import pyperclip

sirka = 500
vyska = 450
data = []
size = []

c = tkinter.Canvas(width=sirka, height=vyska)
c.pack()

def copy():
    cptxt = '('
    for i in range(size[1]):
        cptxt += '0b' + ''.join(str(e) for e in data[i]) + ','
        if i == size[1] - 1:
            cptxt = cptxt[:-1] + ')'
    print(cptxt)
    pyperclip.copy('ahojsvet')

def print_data():
    for i in range(size[1]):
        text = ''.join(str(e) for e in data[i])
        c.create_text(350,15*i+100+i*15,fill='black',text='0b'+text,font='Timer 15')

def clear():
    global data
    # clear old table
    c.delete('all')
    # generate new table
    columns, rows = size
    data = [[y*0 for y in range(columns)] for _ in range(rows)]
    table(*size)
    print_data()

def clickon(event):
    global data
    x = event.x
    y = event.y
    if x <= 10 or x >= 260 or y <= 10 or y >= 410:
        return False
    tag_x = (x - 10) // 50
    tag_y = (y - 10) // 50
    data[tag_y][tag_x] = 1 - data[tag_y][tag_x]
    # clear old table
    c.delete('all')
    # generate new table
    table(*size)
    print_data()

def table(columns, rows):
    for ra in range(rows):
        for co in range(columns):
            color = 'darkblue'
            if data[ra][co] == 1:
                color = 'black'
            c.create_rectangle(co*50+10, ra*50+10,co*50+60,ra*50+60, outline='white', tag='box', fill=color)

def new_screen(columns, rows):
    # create table with data
    global data, size
    size = [columns, rows]
    data = [[y*0 for y in range(columns)] for _ in range(rows)]
    # genrate table
    table(columns, rows)
    # generate button for clear
    clear_button = tkinter.Button(text='Clear',command=clear)
    clear_button.place(x=300,y=420)
    copy_button = tkinter.Button(text='Copy',command=copy)
    copy_button.place(x=250,y=420)
    print_data()

new_screen(5,8)

c.bind('<Button-1>', clickon)
