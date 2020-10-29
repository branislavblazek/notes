total = 0
all_int = []
lowest = None
highest = None

while True:
    line = input('Zadajte číslo alebo Enter pre ukončenie: ')
    if not line:
        break
    try:
        number = int(line)
        total += number
        all_int.append(number)
        if lowest is None or lowest > number:
            lowest = number
        if highest is None or highest < number:
            highest = number
    except ValueError as err:
        print(err)
        continue
print('čísla', all_int)
print('počet = ', len(all_int),
      'súčet = ', total,
      'najmenší = ', lowest,
      'najvyšší = ', highest,
      'priemer = ', total / len(all_int))
    
