#caesar cipher
#ENCODE
def caesar_en(key, word):
    #do result pojde vysledok, do abecedy pojde normalna abeceda
    result = ''
    #ziska abecedu
    abeceda = [chr(x) for x in range(65,91)]
    abeceda.append('_')
    word = word.upper().replace(' ', '_')
    #pre kazde pismeno: vezme jeho index z abecedy
    for i in word:
        code = abeceda.index(i)
        #nejake poriesenie ked je key a index vacsi ako dlzka abecedy
        if code + key >= len(abeceda):
            new_code = (code + key) - len(abeceda)
        else:
            new_code = code + key
        result += abeceda[new_code]
    print(result)

#DECODE
def caesar_de(key, word):
    #do result pojde vysledok, do abecedy pojde normalna abeceda
    result = ''
    #ziska abecedu
    abeceda = [chr(x) for x in range(65,91)]
    abeceda += '_'
    word = word.upper()
    #pre kazde pismeno: vezme jeho index z abecedy
    for i in word:
        #vezme pismeno zo sifry, ten index vezme a odcita a vezme to pismenko
        #z abecedy a ulozi do res
        code = abeceda.index(i)
        if code - key < 0:
            new_code = (code - key) + len(abeceda)
        else:
            new_code = code - key
        if abeceda[new_code] == '_':
            result += chr(32)
        else:
            result += abeceda[new_code]
    print(result)

#get text from input
    #msg - message on input, shouldbe - value what should be in input, maximum - max num
def get_int(msg,shouldbe, maximum):
    while True:
        try:
            line = input(msg + ': ')
            if not line:
                return line
            if shouldbe == 'int':
                i = int(line)
                if i > maximum:
                    print(str(line), 'nemoze byt vacsie ako', maximum)
                    continue
                return i
            elif shouldbe is None:
                return line
            elif line in shouldbe:
                    return line
        except ValueError as Err:
            print(Err)

def caesar():
    while True:
        typ = get_int('Zadajte či chcete text zašifrovať alebo odšifrovať alebo Enter(en/de)', '(en, de)', None)
        #ak je Enter tak ukonci
        if not typ:
            break
        #rozhodni ci enkodujes alebo dekodujes
        if typ == 'en':
            key = get_int('Zadajte kľúč na zašifrovanie', 'int', 26)
        elif typ == 'de':
            key = get_int('Zadajte kľúč na dešifrovanie', 'int', 26)
        #vezme slovo
        word = get_int('Zadajte slovo na šifrovanie', None, None)
        #rozhodne ci  key je cislo alebo Enter
        if not key:
            for i in range(1,27):
                if typ == 'en':
                    caesar_en(i, word)
                else:
                    caesar_de(i, word)
        else:
            if typ == 'en':
                caesar_en(key, word)
            else:
                caesar_de(key, word)
caesar()
