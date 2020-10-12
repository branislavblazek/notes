while True:
    try:
        line = input('input: ')
        try:
            number = int(line)
        except ValueError:
            print('chyba')
            continue
        print(number)
    except EOFError:
        print('EOFError')
        break
