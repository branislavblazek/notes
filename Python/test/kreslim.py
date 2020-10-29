import tkinter;
canvas = tkinter.Canvas(width=600, height=400, bg='white');
canvas.pack();

def vlajka_japonsko():
    canvas.create_oval(200, 100, 400, 300, fill='red', outline='');
    
def vlajka_cesko():
    canvas.create_polygon(0,0,0,400,300,200, fill='blue', outline='');
    canvas.create_polygon(0,0,600,0,600,200,300,200, fill='white', outline='');
    canvas.create_polygon(0,400,600,400,600,200,300,200, fill='red', outline='');
    
def vlajka_grecko():
    #lavy horny stvorec
    canvas.create_rectangle(0,0,80,80, fill='blue', outline='');
    canvas.create_rectangle(120,0, 200,80, fill='blue', outline='');
    canvas.create_rectangle(0,120,80,200, fill='blue', outline='');
    canvas.create_rectangle(120,120,200,200, fill='blue', outline='');
    #kratsie pruhy
    canvas.create_rectangle(200,0,600,40, fill='blue', outline='');
    canvas.create_rectangle(200,80,600,120, fill='blue', outline='');
    canvas.create_rectangle(200,160,600,200, fill='blue', outline='');
    #dolne pruhy
    canvas.create_rectangle(0,240,600,280, fill='blue', outline='');
    canvas.create_rectangle(0,320,600,360, fill='blue', outline='');

inpt = input('Ktorá vlajka štátu sa ti páči?(Japonsko, Česko, Grécko)\n');
if inpt == 'Japonsko':
    vlajka_japonsko();
elif inpt == 'Česko':
    vlajka_cesko();
elif inpt == 'Grécko':
    vlajka_grecko();
else:
    print('Túto vlajku nedokážem nakresliť...');

canvas.mainloop()
