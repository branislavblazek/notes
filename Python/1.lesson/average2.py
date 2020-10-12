total = 0
all_int = []
lowest = None
highest = None

while True:
    try:
        line = input('Zadajte číslo alebo Enter pre ukončenie: ')
        if not line:
            break
        number = int(line)
        total += number
        all_int.append(number)
        if lowest is None or lowest > number:
            lowest = number
        if highest is None or highest < number:
            highest = number
        #pokus o zoradenie pola, sort_list.py
        indexes = []
        indx = 0
        while indx < len(all_int):
            indexes.append(indx)
            indx += 1
        for n in indexes:#aby kod nekoncil 13,12,16 prebehni to cele
            for i in indexes:
                if i + 1 == len(all_int):
                    break
                if all_int[i] > all_int[i+1]:
                    all_int[i], all_int[i+1] = all_int[i+1], all_int[i]
                    indexes = []
                    indx = 0
                    while indx < len(all_int):
                        indexes.append(indx)
                        indx += 1
        #vypocitanie mediana
            #vezmi z pekne zoradeneho pola strednu hodnotu podkial je parne alebo priemer dvoch strednych
        index = int((len(all_int)) / 2)
        median = all_int[index]
        if index and index * 2 == len(all_int):
            median = (all_int[index] + all_int[index-1]) / 2
    except ValueError as err:
        print(err)
print('čísla: ', all_int)
print('počet = ', len(all_int), 'súčet = ', total,
      'najmenší = ', lowest, 'najvyšší = ', highest,
      'priemer = ', total/len(all_int), 'medián = ', median)
