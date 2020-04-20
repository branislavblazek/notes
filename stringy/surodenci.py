vstup = list(input())
pocet = [int(i) for i in input().split(' ')][0]

#skontroluj ci je symetricky
je_symetricke = True

polka = len(vstup) // 2
for letter in range(polka):
    if vstup[letter] != vstup[-letter-1]:
        je_symetricke = False
        break

res = []

for _ in range(pocet):
    pozicia, pismeno = [i for i in input().split(' ')]
    pozicia = int(pozicia)
    vstup[pozicia] = pismeno

    if vstup[pozicia] == vstup[-pozicia-1] and je_symetricke:
        res.append('ano')
    else:
        for letter in range(polka):
            if vstup[letter] != vstup[-letter-1]:
                je_symetricke = False
                res.append('nie')
                break
        else:       
            res.append('ano')
            je_symetricke = True

print(*res, sep='\n')