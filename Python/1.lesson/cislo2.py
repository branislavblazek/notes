print('Zadajte celé číslo, za každým stlačte Enter; alebo Ctrl+D(Unix) aleboCtrl+Z(Win) pre ukončenie');

total = 0
count = 0
average = 0
all_int = []

while True:
    try:
        line = input('Číslo:\n')
        if line:
            number = int(line)
            total += number
            count += 1
            average = total / count
            all_int.append(number)
    except ValueError as err:
        print(err)
        continue
    except EOFError as err:
        print('EOFError\n')
        break

if count:
    print('počet =', count, '\ncelkom = ', total, '\npriemer = ', average, '\nčísla = ' , all_int)
