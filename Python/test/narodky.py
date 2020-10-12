import tkinter;
c = tkinter.Canvas(width=400, height=200, bg='pink');
c.pack();
c.create_text(70, 40, text='o', fill='orange', font='Arial 20');
c.create_text(100, 40, text='1', fill='red', font='Arial 30');
c.create_text(170, 40, text='mesiacov', fill='orange', font='Arial 20');
c.create_text(150, 80, text='budeš mať narodeniny!', fill='orange', font='Arial 20');
c.create_text(200, 120, text='VŠETKO NAJLEPŠIE!', fill='red', font='Arial 25');
c.mainloop();
