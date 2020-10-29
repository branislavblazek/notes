print('Zadajte celé číslo, za každým stlačte Enter; alebo Enter pre ukončenie');

total = 0
count = 0
average = 0

while True:
    line = input('Číslo:')
    if line:
        try:
            number = int(line)
        except ValueError as err:
            print(err)
            continue
        total += number
        count += 1
        average = total / count 
    else:
        break

if count:
    print('počet =', count, 'celkom = ', total, 'priemer = ', average)
