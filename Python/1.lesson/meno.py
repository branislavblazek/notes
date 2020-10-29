print('Zadajte Vaše mená; alebo Ctrl+D(Unix) aleboCtrl+Z(Win) pre ukončenie')

total = 0
all_names = []
najdlhsie = ""
najkratsie = ""

while True:
    try:
        line = input('Meno:')
        if line:
            total += 1
            line = str(line)
            all_names.append(line)
    except ValueError as err:
            print(err)
            continue
    except EOFError:
            print('EOFError')
            break;

if total:
    for meno in all_names:
        print('ahoj, volám sa', meno)
