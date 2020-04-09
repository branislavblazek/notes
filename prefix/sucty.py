n = int(input())
povodny_list = [int(i) for i in input().split(' ')]
prefix = [0]
suma = 0
for cislo in povodny_list:
    suma += cislo
    prefix.append(suma)

otazok = int(input())
res = []
for i in range(otazok):
    l, r = [int(i) for i in input().split(' ')]
    res.append(prefix[r] - prefix[l-1])