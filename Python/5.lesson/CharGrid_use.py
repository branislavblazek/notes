import CharGrid as grid

grid.resize(20,20, '_')
for i in range(10):
    ch = 'x' if i % 2 == 0 else '_'
    grid.add_rectangle(i,i,20-i,20-i, char=ch, fill=True)
grid.set_background('.')
grid.render(True)
