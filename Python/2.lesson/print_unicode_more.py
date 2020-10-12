import sys
import unicodedata

def print_unicode_table(words):
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
        ok = True
        for word in words:
            if word not in name.lower():
                ok = False
                break
        if ok:
            print("{0:6}   {0:5X}   {0:^3c}   {1}".format(code, name.title()))
        code += 1

words = []
if len(sys.argv) > 1:
    if sys.argv[1] in ('-h', '--help'):
        print('pouzitie: {0} [retazec]'.format(sys.argv))
        words = None
    else:
        for word in sys.argv[1:]:
            words.append(word.lower())
else:
    print('pouzitie: {0} [retazec]'.format(sys.argv))

print(words)
if words is not None:
    print_unicode_table(words)
