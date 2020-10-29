import random

prvky = {
    'H': 'vodik', 'He': 'helium',
    'Li': 'litium', 'Be': 'berylium', 'B': 'bor', 'C': 'uhlik', 'N': 'dusik', 'O': 'kyslik', 'F': 'fluor', 'Ne': 'neon',
    'Na': 'sodik', 'Mg': 'horcik', 'Al': 'hlinik', 'Si': 'kremik', 'P': 'fosfor', 'S': 'sira', 'Cl': 'chlor', 'Ar': 'argon',
    'K': 'draslik', 'Ca': 'vapnik', 'Sc': 'skandium', 'Ti': 'titan', 'V': 'vanad', 'Cr': 'chrom', 'Mn': 'mangan', 'Fe': 'zelezo', 'Co': 'kobalt', 'Ni': 'nikel', 'Cu': 'med', 'Zn': 'zinok', 'Ga': 'galium', 'Ge': 'germanium', 'As': 'arzen', 'Se': 'selen', 'Br': 'brom', 'Kr': 'krypton',
    'Rb': 'rubidium', 'Sr': 'stroncium', 'Y': 'ytrium', 'Zr': 'zirkonium', 'Nb': 'niob', 'Mo': 'molybden', 'Tc': 'technecium', 'Ru': 'rutenium', 'Rh': 'rodium', 'Pd': 'paladium', 'Ag': 'striebro', 'Cd': 'kadmium', 'In': 'Indium', 'Sn': 'cin', 'Sb': 'antimon', 'Te': 'telur', 'I': 'jod', 'Xe': 'xenon',
    'Cs': 'cezium', 'Ba': 'barium', 'Hf': 'hafnium', 'Ta': 'tantal', 'W': 'volfram', 'Re': 'renium', 'Os': 'osmium', 'Ir': 'iridium', 'Pt': 'platina', 'Au': 'zlato', 'Hg': 'ortut', 'Tl': 'talium', 'Pb': 'olovo', 'Bi': 'bizmut', 'Po': 'polonium', 'At': 'astat', 'Rn': 'radon',
    'Fr': 'francium', 'Ra': 'radium'}

def get_question():
    skratka, prvok = random.choice(list(prvky.items()))
    i = random.randint(0,1)
    if i == 0:
        vstup = input('Aky prvok ma skratku {}: '.format(skratka))
        spravna = prvok
    else:
        vstup = input('Aka skratka patri prvku {}: '.format(prvok))
        spravna = skratka

    return vstup, spravna

def check(vstup, odpoved):
    odpoved = odpoved.lower()
    while True:
        vstup = vstup.strip(' ').lower()
        #spravne
        if vstup == odpoved:
            print(random.choice(('Spravne!', 'Gratulujem', 'Len tak dalej', 'Presne tak', 'Ano', 'Mas pravdu')))
            return True
            break
        #neviem
        elif vstup == "neviem":
            print('spravna odpoved je {}'.format(odpoved))
            return True
            break
        #pomoc
        elif vstup == "pomoc":
            if len(odpoved) == 1:
                print('Skratka je prve pismenko z nazvu')
            elif len(odpoved) == 2:
                print('druhe pismenko je {}'.format(odpoved[1]))
            else:
                print('prve dve pismenka su {}'.format(odpoved[:2]))
        #skoncit
        elif not vstup:
            return False
            break
        #zle
        elif vstup != odpoved:
            print(random.choice(('Zle', 'Nespravne', 'Ee', 'Nie', 'Nije', 'To nie je pravda', 'Mozno nabuduce')))
        else:
            return False
            break
        
        vstup = input('Zadajte este raz: ')

while True:
    vstup, spravna = get_question()
    if not check(vstup, spravna):
        break
