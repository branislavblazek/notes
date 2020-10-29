import math

def koeficient_korelacie(data_x, data_y):
    n = len(data_x)
    priemer_x = sum(data_x) / n
    priemer_y = sum(data_y) / n

    sucet_x = 0
    sucet_y = 0
    nasob = 0

    print('{0:_^151}'.format(''))
    print('|{0:^7}|{1:^20}|{2:^20}|{3:^20}|{4:^20}|{5:^20}|{6:^20}|{7:^21}|'.format('index', 'xi', 'yi', 'xi-x̄', 'yi-ȳ', '(xi-x̄)^2', '(yi-ȳ)^2', '(xi-x̄)(yi-ȳ)'))
    print('{0:-^151}'.format(''))

    for index in range(len(data_x)):
        rozdiel_x = data_x[index] - priemer_x
        rozdiel_y = data_y[index] - priemer_y
        
        mocnina_x = rozdiel_x ** 2
        mocnina_y = rozdiel_y ** 2

        sucet_x += mocnina_x
        sucet_y += mocnina_y

        nasobok = rozdiel_x * rozdiel_y
        nasob += nasobok

        print('|{0:^7}|{1:^20}|{2:^20}|{3:^+19.2f}|{4:^+19.2f}|{5:^+19.2f}|{6:^+19.2f}|{7:^+19.2f}|'.format(index+1, data_x[index], data_y[index], rozdiel_x, rozdiel_y, mocnina_x, mocnina_y, nasobok))
        print('{0:-^151}'.format(''))

    s1 = math.sqrt(sucet_x / n)
    s2 = math.sqrt(sucet_y / n)
    k = nasob / n
    r = k / (s1*s2)

    print('pocetnost:', n)
    print('priemer _x_:', '{0:^.4f}'.format(priemer_x))
    print('priemer _y_:', '{0:^.4f}'.format(priemer_y))
    print('sucet (xi-_x_)^2:', '{0:^.4f}'.format(sucet_x))
    print('sucet (y1-_y_)^2:', '{0:^.4f}'.format(sucet_y))
    print('sucet pre k:', '{0:^.4f}'.format(nasob))
    print('k:', '{0:^.4f}'.format(k))
    print('smerodajna odchylka x:', '{0:^.4f}'.format(s1))
    print('smerodajna odchylka y:', '{0:^.4f}'.format(s2))
    print('koeficient korelacie r:', '{0:^.4f}'.format(r))


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