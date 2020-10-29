def main():
    while True:
        try:
            line = input()
            extract_fields(line)
        except EOFError:
            break

def extract_fields(line):
    fields = []
    field = ''
    quote = None#ukldada sa typ apostrofu
    for c in line:#prebehne kazde jedno pismenko
        if c in '\'"':#ak je dane pismeno ' alebo "
            if quote is None:
                #toto ozncajue zaciatok stringu
                quote = c#nastavi typ apostrofu
            elif quote == c:#ak je pismenko ako apostrof
                quote = None#tak proste ukonci
            else:#inak, vsetko to co je medzti apostrofmi
                field += c#pridaj do field
            continue#a stale to opakuj
        #pokial znak nie je ' "
        if quote is None and c == ',':
            #ak tam je ciarka tak pridaj field fo fields
            fields.append(field)
            field = ''
            #inak pridaj znak do field
        else:
            field += c
    #osetrenie posledneho pola
    if field:
        fields.append(field)
    return fields

main()
