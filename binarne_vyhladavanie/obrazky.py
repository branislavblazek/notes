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
    if stred != 0:
        for i in range(sady):
            riadok += vzory[i] // stred
    if riadok >= mriezka:
        l = stred+1
    else:
        r = stred-1

if pokracuj:
    stred = (l+r)//2
    riadok = 0
    if stred != 0:
        for i in range(sady):
            riadok += vzory[i] // stred

    if riadok < mriezka and stred != 0:
        print(mriezka // stred)
    else:
        print(stred)