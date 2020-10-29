veta = 'Ahoj, volam sa {} a je mi {} rokov!'
print(veta.format('Branislav Blazek', 16))
veta2 = 'Chodim na skolu {school} do {0} rocnika'
print(veta2.format(1, school='GVOZA'))
auta = ['Tesla', 'Audi' , 'Opel', 'BMW']
veta3 = 'Raz si kupim auto od znacky {0[0]}'
print(veta3.format(auta))
d = dict(animal='Slon', weight='10000')
veta4 = 'Moj domaci maznacik je {0[animal]} a vazi {0[weight]}'
print(veta4.format(d))

#rozbalenie mapovania
element = 'Striebro'
number = 55
veticka = 'Prvok {element} ma cislo {number}'
print(veticka.format(**locals()))

#formatovanie
    #text
s = 'Dnes je velmi krasny den!'
print("{0}".format(s)) #prednastavene
print("{0:25}".format(s)) #minimalna sirka 25
print("{0:>40}".format(s)) #zarovananie doprava
print("{:^40}".format(s)) #zarovananie na stred
print("{0:x^40}".format(s)) #zarovananie na stred + vypln
print("{0:_<40}".format(s)) #zarovananie doprava
print("{:.10}".format(s)) #maximalna sirka
maxwidth = 12
print("{0}".format(s[:maxwidth]))
print("{0:.{1}}".format(s, maxwidth))
    #cisla
print("{0:0=12}".format(123456789)) #vyplni nulami do 12
print("{0:012}".format(123456789)) #vyplni nulami do 12
print("{0:*<15}".format(123456789))
print("{0:*>15}".format(123456789))
print("{0:*^15}".format(123456789))
print("[{0:}] [{1:}]".format(12345, -12345))
print("[{0:+}] [{1:+}]".format(12345, -12345))
print("[{0:-}] [{1:-}]".format(12345, -12345))
print("{0:,}".format(987654321))

