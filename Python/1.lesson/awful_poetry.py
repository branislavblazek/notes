from random import *

zamena = ['môj', 'tvoj', 'jeho', 'jej', 'náš', 'váš']
mena = ['mačka', 'vlak', 'strom', 'muž', 'žena', 'kôň', 'pes']
slovesa = ['skáče', 'rozpráva', 'pláva', 'odpisuje']
prislovky = ['kvalitne', 'ticho', 'nahlas', 'hrozne', 'hrubo', 'zdvorilo']
while True:
    try:
        i = int(input('Zadajte počet riadkov: '))
    except ValueError:
        print('Máš zadať číslo, nič viac...')
        continue
    while i:
        zameno = choice(zamena)
        meno = choice(mena)
        sloveso = choice(slovesa)
        if randint(0,1) == 0:
            print(zameno, meno, sloveso)
        else:
            prislovka = choice(prislovky)
            print(zameno, meno, prislovka, sloveso)
        i -= 1
    break
