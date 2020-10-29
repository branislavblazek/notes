n, hodiny = [int(i) for i in input().split(' ')]
# FIX: Toto je o chlp rychlejsie, ked sa ta funkcia int() pouzije rovno pri
#      list-comprehension
data = [int(i) for i in input().split(' ')]

# vytvor prefixove pole
prefix = [0]

for x in data:
    prefix.append(prefix[-1] + x)

pocet = {}
odpoved = 0

# FIX: Iterovanie priamo cez pole je o chlp rychlejsie ako pritupovanim cez
#      riadiacu premennu (teda ako for i in range(hodiny):)
for x in prefix[:hodiny + 1]:
    pocet[x] = pocet[x] + 1 if x in pocet else 1

odpoved = pocet[prefix[0]] - 1

# FIX: Aby tu nemusel byt "if idx > 0" (kazdy if o trochu spomaluje kod), zacal som cyklus
#      od 1
for idx in range(1, len(prefix) - hodiny):
    pocet[prefix[idx-1]] -= 1

    # FIX: Aby tu nemusel byt if, dopocitava sa ten zbytok (ked okno presahuje pole) na konci.
    pocet[prefix[idx + hodiny]] = pocet[prefix[idx + hodiny]] + 1 if prefix[idx + hodiny] in pocet else 1
    odpoved += pocet[prefix[idx]] - 1
    

# FIX: Tu sa dopocitava zbytok.
pocet[prefix[len(prefix) - hodiny -1]] -= 1
for x in pocet.keys():
    odpoved += (pocet[x]*(pocet[x]-1)//2)
print(odpoved)