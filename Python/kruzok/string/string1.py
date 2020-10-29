slovo = 'ahojsvet'
slovo = '*' + slovo[1:]
#ord vrati ASCII kod, cez chr() nam vrati znak podla indexu
abeceda = ''
for i in range(65,91):
    abeceda += chr(i)

#sifrovanie
slovo = 'Popocatepetl'
    
sifra1 = ''
for i in slovo:
    sifra1 += i + '*'

#ceasir cipher
def caesar_en(key, word):
    sifra2 = ''
    abeceda = ''
    slovo = word
    for i in range(65,91):
        abeceda += chr(i)
    slovo = slovo.upper()
    for i in slovo:
        code = abeceda.index(i)
        if code + key > len(abeceda):
            new_code = (code + key) - len(abeceda)
        else:
            new_code = code + key
        sifra2 += abeceda[new_code]
    print(sifra2)

key = int(input('Zadajte kluc na sifrovanie'))
word = str(input('Zadajte slovo na zasifrovanie'))
caesar_en(key, word)


#vigenere cipher
#ENCODE
def vigenere_en(key, sentence):
    #nastavi dlzku kluc na dlzku vety
    nova_dlzka = len(sentence) // len(key) + len(sentence) % len(key)
    key = nova_dlzka * key
    #da na upper, ziska abecedu
    sentence = sentence.upper()
    key = key.upper()
    abeceda = ''
    for i in range(65,91):
        abeceda += chr(i)
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
    abeceda = ''
    for i in range(65,91):
        abeceda += chr(i)
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
        result += letter
        i += 1
    print(result)
    
    
def vigenere():
    typ = str(input('Zadajte ci chcete text enkodovat alebo dekodovat(en/de): '))
    key = str(input('Zadajte kluc pre tuto enigmu: '))
    if typ == 'en':
        sentence = str(input('Zadajte spravu na sifrovanie: '))
        vigenere_en(key, sentence)
    elif typ == 'de':
        sentence = str(input('Zadajte spravu na desifrovanie: '))
        vigenere_de(key, sentence)
    
vigenere()
