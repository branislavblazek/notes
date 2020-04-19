import math

def koeficient_korelacie(data_x, data_y):
    n = len(data_x)
    priemer_x = sum(data_x) / n
    priemer_y = sum(data_y) / n

    sucet_x = 0
    sucet_y = 0
    nasob = 0

    for index in range(len(data_x)):
        rozdiel_x = data_x[index] - priemer_x
        rozdiel_y = data_y[index] - priemer_y

        sucet_x += rozdiel_x ** 2
        sucet_y += rozdiel_y ** 2
        nasob += rozdiel_x * rozdiel_y

    s1 = math.sqrt(sucet_x / n)
    s2 = math.sqrt(sucet_y / n)
    k = nasob / n
    r = k / (s1*s2)

    print('pocetnost:', n)
    print('priemer _x_:', priemer_x)
    print('priemer _y_:', priemer_y)
    print('sucet (xi-_x_)^2:', sucet_x)
    print('sucet (y1-_y_)^2:', sucet_y)
    print('sucet pre k:', nasob)
    print('k:', k)
    print('smerodajna odchylka x:', s1)
    print('smerodajna odchylka y:', s2)
    print('koeficient korelacie r:', r)


print('Tvar vstupu:')
print('x1 y1')
print('x2 y2')
print('...')
print('xj yj')
print('Zadaj hondoty znaku pre x a y:')
data_x = []
data_y = []
vstup = input()
while vstup:
    cislo_x, cislo_y = [int(i) for i in vstup.split(' ')]
    data_x.append(cislo_x)
    data_y.append(cislo_y)
    vstup = input()

koeficient_korelacie(data_x, data_y)
print('Stlacenim enteru vypni program...')
input()