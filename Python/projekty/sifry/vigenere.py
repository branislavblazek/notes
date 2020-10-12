#vigenere cipher
#ENCODE
def vigenere_en(key, sentence):
    #nastavi dlzku kluc na dlzku vety
    nova_dlzka = len(sentence) // len(key) + len(sentence) % len(key)
    key = nova_dlzka * key
    #da na upper, ziska abecedu a ako medzera posluzi _
    sentence = sentence.upper()
    key = key.upper()
    abeceda = [chr(x) for x in range(65,91)]
    abeceda.append('_')
    #ak je znak medzera tak ho nahradi _
    sentence = sentence.replace(' ', '_')
    #vypise podla akeho pismena ma abeceda zacinat
    i = 0
    #result, do tohoto sa ulozi vysledok
    result = ''
    while i < len(sentence):
        #ziska abecedu podla key[i]
        #z abacedy vezme index pismena podla key[i], odlepi tak aby abeceda
        #zacinala danym pismenom a odobratu cast prilepi na koniec abecedy
        prilep = abeceda.index(key[i])
        nova_abeceda = abeceda[prilep:] + abeceda[:prilep]
        #vezme index pismena zo starej abecedy a z novej abecedy vezme
        #pismeno na danom indexe
        index = abeceda.index(sentence[i])
        letter = nova_abeceda[index]
        result += letter
        i += 1
    print(result)
    
#DECODE
def vigenere_de(key, sentence):
    #nastavi dlzku kluc na dlzku vety
    nova_dlzka = len(sentence) // len(key) + len(sentence) % len(key)
    key = nova_dlzka * key
    #da na upper, ziska abecedu
    sentence = sentence.upper()
    key = key.upper()
    abeceda = [chr(x) for x in range(65,91)]
    abeceda.append('_')
    #vypise podla akeho pismena ma abeceda zacinat
    i = 0
    #result, do tohoto sa ulozi vysledok
    result = ''
    while i < len(sentence):
        #vytvori abecedu ktora zacina podla key[i], odlepi abecedu tak aby
        #abeceda zacinala danym pismenom a odobratu cast da na koniec
        prilep = abeceda.index(key[i])
        nova_abeceda = abeceda[prilep:] + abeceda[:prilep]
        #vezme index pismena na ktorom je znak v sentence, ten index vezme z
        #upravenej abecedy a z normalnej abecedy vytiahne
        #pismeno a to je dekodovane
        index = nova_abeceda.index(sentence[i])
        letter = abeceda[index]
        if letter == '_':
            letter = chr(32)
        result += letter
        i += 1
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
    
def vigenere():
    while True:
        typ = get_int('Zadajte ci chcete text enkodovat alebo dekodovat(en/de)', '(en, de)', None)
        if not typ:
            break
        sentence = get_int('Zadajte slovo na šifrovanie', None, None)
        if typ == 'en':
            key = get_int('Zadajte kľúč na zašifrovanie', None, None)
            vigenere_en(key, sentence)
        elif typ == 'de':
            key = get_int('Zadajte kľúč na dešifrovanie', None, None)
            vigenere_de(key, sentence)   
vigenere()
