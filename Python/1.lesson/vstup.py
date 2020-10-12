print('Zadajte celočíselné hodnoty a stlačte Enter, v prípade skončenie stlačte Enter')

total = 0
count = 0

while True:
    try:
        line =  input('čislo: ')
        if line:
            number = int(line)
    except ValueError:
        print('Zadajte celé číslo!')
        continue
    except EOFError:
        break
    total += number
    count += 1

if count:
    print(total, count)
