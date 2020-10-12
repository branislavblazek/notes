import random;
#random variables
rndm_poh = random.choice(('muž', 'žena'));
#ziskanie mena
name = input('Ahoj, my sa pravdepodobne nepoznáme, já som think_machine.py a ty?\n');
print('Teší ma ' + name);
#ziskanie pohlavia
poh = input('Podľa tvojho mena usudzujem že si ' + rndm_poh + ', je to tak?\n');
#akceptovanie viacerych odpovedi
if poh == 'áno' or poh == 'ano' or poh == 1 or poh == 'jj' or poh == 'jo' or poh == 'yes' or poh == 'yop': poh_fdbck = 1
else: poh_fdbck = 0
if (rndm_poh == 'muž' and poh_fdbck == 1) or (rndm_poh == 'žena' and
poh_fdbck == 0): print('Super, budem vedieť že si muž')
elif (rndm_poh == "žena" and poh_fdbck == 1) or (rndm_poh == 'muž' and poh_fdbck == 0):
        print('Fajn, budem si pamätať že si žena');
#ziskanie veku
age = int(input('Koľko máš rokov?\n'));
#poriešiť nejako cez polia aby sklonovalo mena podla rodov
if age < 0:
    print('Dáko mi to nevychádza...\n');
elif age <= 6:
    print('Celkom si ešte mladý(á)! Akoto že vieš čítať a písať tak dobre?\n');
elif age <= 14:
    print('Ako ti ide základka? Ver mi, stredná je ešte ťažšia\n');
elif age <= 20:
    age_high = input('Na ktorú strednú školu chodíš?\n');
    if age_high in ('GVOZA', 'GVOZU', 'gvoza', 'gvozu', 'Gvozu', 'Gvoza'):
        print('Supeeeeeer :) môjho autora nájdeš na tejto škole :) #GvozaJeZivot');
    else:
        print('Tak nech sa ti darí :)');
elif age < 100:
    print('Tak sa užívaj život :)');
else:
    print('Nejsi nejaký starý?'); 
#ziskanie oblubeneho konicka
hobby_choice = random.choice(('behanie', 'bicyklovanie', 'hranie na hudobný nástroj', 'plávanie'));
hobby = input('Je tvoj obľúbený koníček ' + hobby_choice + '\n');
if hobby_choice == 'behanie' and hobby is ('áno', 'ano', 'jo', 'jj', 'true', 1):
    print('To je tiež môj obľúbený koníček');
else:
    print('Tak to fajne');
#ziskanie mesiaca narodenia
actual_month = 10;
month = int(input('V ktorom mesiaci si sa narodil? (číslo mesiaca)\n'));
if (actual_month > month):
    pocitaj = actual_month - month;
    print('O ' + str(pocitaj) + ' mesiacov budeš mať narodeniny!');
elif (actual_month == month):
    print('Narodeniny máš/mal si tento mesisac! Všetko najlepšie');
elif (actual_month < month):
    pocitaj = month - actual_month;
    print('O ' + str(pocitaj) + ' mesiacov budeš mať narodeniny!');
#vykreslenie torty 
