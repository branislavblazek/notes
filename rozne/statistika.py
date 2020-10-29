import math

def statistika_suboru(data):
    n = len(data)
    #priemer hodnot
    ar_priemer = sum(data) / n
    va_priemer = 0

    #sucet druhych mocnin rozdielu itemu a priemeru
    sucet = 0
    sucet_vah = 0

    #pocet jednotlivych znakov
    pocet = {}
    for item in data:
        #pre vypocet smerodajnej
        rozdiel = (item - ar_priemer) ** 2
        sucet += rozdiel
        #pre pocetnost
        pocet[item] = pocet[item] + 1 if item in pocet else 1

    modus = 0
    modus_pocet = 0
    for item in pocet.items():
        #pre vazeny priemer
        va_priemer += item[0]*item[1]
        sucet_vah += item[1]
        #pre modus
        if item[1] > modus_pocet:
            modus = item[0]
            modus_pocet = item[1]

    if n % 2 != 0:
        median = data[n // 2]
    else:
        median = (data[n // 2] + data[n // 2 - 1]) / 2

    podiel = sucet / n
    smerodajna = math.sqrt(podiel)

    variacny = smerodajna / ar_priemer * 100

    va_priemer = va_priemer / sucet_vah

    print('pocetnost:', n)
    print('aritmeticky priemer:', ar_priemer)
    print('vazeny priemer:', va_priemer)
    print('sucet:', sucet)
    print('modus:', modus)
    print('vyskyt modusu:', modus_pocet)
    print('median:', median)
    print('variacny koeficient:', variacny)
    print('smerodajna odchylka:', smerodajna)

#udaje = [22, 16, 21, 27, 30, 21, 33, 29, 21, 23, 27, 29]
print('Tvar vstupu:')
print('x1 n1')
print('x2 n2')
print('...')
print('xj nj')
print('Zadaj cisla s ich pocetnostnou oddelene po riadkoch:')
data = []
vstup = input()
while vstup:
    cislo, pocetnost = [int(i) for i in vstup.split(' ')]
    for _ in range(pocetnost):
        data.append(cislo)
    vstup = input()

statistika_suboru(data)
print('Stlacenim enteru vypni program...')
input()