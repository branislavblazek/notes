import sys
import unicodedata

def print_unicode_table(word):
    #vypise hornu uvodnu cast
    print('desat.   hex.   znak   {0:^40}'.format('nazov'))
    print('{0:-^{1}}   {0:-^{2}}   {0:-^{3}}   {0:-^40}'.format('', len('desat.'), len('hex.'), len('znak')))
    #medzera je prvy znak, vezme jej unicode cislo
    code = ord(" ")
    #nastavi end
    end = min(0xD800, sys.maxunicode)

    while code < end:
        #vezme pismenko z unicode tabulky pre dany kod
        c = chr(code)
        #vezme nazov pismenka
        name = unicodedata.name(c, "*** nazname ***")
        if word is None or word in name.lower():
            #vypise dane pismenko do tabulky
            print("{0:7}   {0:5X}   {0:^3c}   {1}".format(code, name.title()))
        code += 1

word = None
if len(sys.argv) > 1:
    if sys.argv[1] in ('-h', '--help'):
        print('pouzitie: {0} [retazec]'.format(sys.argv))
        word = 0
    else:
        word = sys.argv[1].lower()
else:
    print('pouzitie: {0} [retazec]'.format(sys.argv))
if word != 0:
    print_unicode_table(word)
