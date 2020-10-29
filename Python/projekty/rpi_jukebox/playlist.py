playlist = ['7 Years', 'Nothing else matters', 'High hopes', 'Nazdar']

# function for displaying two items on display

def main(playlist):
    # create items list where are all items to diplay
    items = ['random', 'by order']
    items = items + playlist
    # point on one item
    pointer = 0
    # stored pointers of 2 items what to show
    show = [0,1]
    # getting input, set pointer and display 2 items
    while True:
        button = input('select where you want go')
        # go one positions  up
        if button == 'w':
            # change pointer
            if pointer - 1 < 0:
                pointer = pointer
            else:
                pointer -= 1
            # change show list
            if pointer in show:
                show = show
            else:
                show[0] = pointer
                show[1] = pointer + 1
        # one position down
        elif button == 's':
            # change pointer
            if pointer + 1 > len(items) - 1:
                pointer = pointer
            else:
                pointer += 1
            # change show list
            if pointer in show:
                show = show
            else:
                show[0] = pointer - 1
                show[1] = pointer
        elif button == 'a':
            print('playing ' + items[pointer])
        print()
        print(items[pointer])
        print(items[show[0]])
        print(items[show[1]])
            
    
main(playlist)
