#vstup
mriezka, sady = [int(i) for i in input().split(' ')]
vzory = []
for i in range(sady):
    vzory.append(int(input()))

#binsearch
l = 0
r = mriezka+1
pokracuj = 1
while (l - r < 1):
    stred = (l+r)//2
    riadok = 0
    for i in range(sady):
        if stred == 0:
            riadok = 1
        else:
            riadok += vzory[i] // stred

    if riadok >= mriezka:
        l = stred+1
    else:
        r = stred-1

if pokracuj:
    stred = (l+r)//2
    riadok = 0
    for i in range(sady):
        if stred <= 0:
            riadok = 1
        else:
            riadok += vzory[i] // stred

    if riadok < mriezka:
        if stred <= 0:
            print(1)
        else:
            print(mriezka // stred)
    else:
        print(stred)