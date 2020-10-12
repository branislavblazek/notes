
import sys
import random

def main():
    #tu sa budu ukldata vsetky slovicka v type slovnik[slovicko] = 'preklad [synonym]'
    slovnik = dict()

    #prve spustenie, ziskanie suborov
    if len(sys.argv) < 2 or sys.argv[1] in {'-h', '--help', 'pomoc'}:
        print('pouzitie: {} slovnik1 [slovnik2 ...[slovikN]]'.format(sys.argv[0]))
        sys.exit()
    for filename in sys.argv[1:]:
        for line in open(filename):
            #subory obsahuju data typu: slovicko, preklad [synonym]
            line = line.strip()
            if line:
                left, right = line.split(',')
                slovnik[left] = right
    #nacitanie otazok
    while True:
        vstup, spravna = question(slovnik)
        if not check(vstup, spravna):
            break


def question(slovnik):
    q = dict()
    q[0], q[1] = random.choice(list(slovnik.items()))
    pytajsa = random.choice(q).strip()
    oddel = print('{0:-<60}'.format(''))
    vstup = input('Aky je preklad {}: '.format(pytajsa))
    if pytajsa == q[0]:
        spravna = q[1]
    else:
        spravna = q[0]
    return vstup, spravna

def check(vstup, spravna):
    spravna = spravna.strip()
    if len(spravna) > 1:
        spravna = [x for x in spravna.split(' ')]
    while True:
        vypis = True
        #ak je odpoved spravna
        if vstup in spravna and vstup is not '':
            print(random.choice(('Spravne!', 'Gratulujem', 'Len tak dalej', 'Presne tak', 'Ano', 'Mas pravdu')))
            return True
            break
        #neviem
        elif vstup == 'neviem':
            print('Spravna odpoved je {}'.format(spravna))
            return True
            break
        #skoncit
        elif not vstup:
            print('Naozaj chces skoncit tento test? (Y/n)')
            vypis = False
        elif vstup == 'Y':
            print('Ukoncujem test...')
            return False
            break
        elif vstup == 'n':
            print('Mozes pokracovat v teste :)')
        #ak je zla odpoved
        elif vstup not in spravna:
            print(random.choice(('Zle', 'Nespravne', 'Ee', 'Nie', 'Nije', 'To nie je pravda', 'Mozno nabuduce')))

        if vypis:
            vstup = input('Zadaj odpoved este raz: ')
        else:
            vstup = input()

main()