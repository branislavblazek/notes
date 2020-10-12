#!/usr/bin/python3
import os

def main():
    new_changes = False
    items_in_file = []
    filename, items_in_file = choose_file()
    if not filename:
        print('Program ukonceny...')
        return
    
    while True:
        print('\nStrazca zoznamu\n')
        print_lines(items_in_file)
        now_to_do = get_choice(items_in_file, new_changes)

        if now_to_do in ('p'):
            new_changes = add_item(items_in_file, new_changes)
        elif now_to_do in ('v'):
            new_changes = delete_item(items_in_file, new_changes)
        elif now_to_do in ('u'):
            new_changes = save_list(filename, items_in_file)
        elif now_to_do in ('k'):
            if (new_changes and get_string('Chcete ulozit zmenene informacie (a/n)', "ano/nie", "a").lower() in ('a', 'ano')):
                save_list(filename, items_in_file, True)
            break

def add_item(items, new_changes):
    item = get_string('Pridat prvok', "item")
    if item:
        items.append(item)
        items.sort(key=str.lower)
        return True
    return new_changes

def delete_item(items, new_changes):
    which = get_integer('Vymazat prvok (alebo 0 pre zrusenie vymazania)', "number", maximum=len(items), allow_zero=True)
    if which == 0:
        return new_changes
    else:
        del items[which-1]
        return True

def save_list(filename, items, terminating=False):
    fh = None
    try:
        fh = open(filename, mode="w", encoding="utf8")
        fh.write("\n".join(items))
        fh.write("\n")
    except EnvironmentError as err:
        print('CHYBA: nemozem ulozit {0}: {1}'.format(filename, err))
        return True
    else:
        print('Zoznam bol ulozeny do {0}, celkom ulozenych prvkov: {1}'.format(filename, len(items)))
        if not terminating:
            input("Pre pokracovanie stlacte Enter...")
        return False
    finally:
        if fh is not None:
            fh.close()
        
def get_choice(items, new_changes):
    """
    Ponuka userovi zvolit si co za akciu chce robit
    """
    while True:
        #pokial tam je viac itemov
        if items:
            #pokial nie je ulozene
            if new_changes:
                menu = "Pridat[p] Vymazat[v] Ulozit[u] Koniec[k]"
                valid_choices = ('pvuk')
            else:
                menu = "Pridat[p] Vymazat[v] Koniec[k]"
                valid_choices = ('pvk')
        #pokial nula
        else:
            menu = "Pridat[p]   Koniec[k]"
            valid_choices = ("pk")
        #teraz som ziskal co chcem napisat aj co si moze user vybrat
        user_wants = get_string(menu, "choice", default='p').lower()
        #skontroluj vstup
        if user_wants not in valid_choices:
            print('CHYBA: neplatna volba--zadajte niektoru z tychto moznosti: "{0}"'.format(valid_choices))
            input('pre pokracovanie stlacte Enter...')
        else:
            return user_wants.lower()

def choose_file():
    """
    funkcia vracia nazov subra a obsah vybraneho subora
    pokial sa nic nenachadza v aktualnom priecinku, vytvara novy subor, 
    pokial tam uz nieco je, da userovy na vyber ktory subor chce citat. 
    pokial user da 0, vytovri sa novy
    pokial user stlaci ine cislo, precita sa ten subor
    """
    create_new = False
    print("\nStrazca zoznamu\n")
    #dostane zozmam suborov v adresary konciach .lst
    files = [x for x in os.listdir('.') if x.endswith('.lst')]
    #pokial neexistuje nic, vytvor novy
    if not files:
        create_new = True

    #pokial sa nema vytvorit novy
    if not create_new:
        #ak ich tu je viac, tak ich vypis a daj na vyber userovi aky si ma vybrat
        print_lines(files)
        number_file = get_integer('Zvolte cislo suboru (alebo 0 pre vytvorenie noveho)', "integer", minimum=0, maximum=len(files), allow_zero=True)
        #pokial sa ma zadat novy
        if number_file == 0:
            create_new = True
        else:
            filename = files[number_file-1]
            items_in_file = get_lines(filename)
    #pokial sa ma vytvorit novy
    if create_new:
        #ziskaj meno
        filename = get_string('Zadajte nazov suboru', "string")
        if not filename.endswith('.lst'):
            filename += '.lst'
        items_in_file = []
    #vrat meno a prvky
    return filename, items_in_file

def get_lines(filename):
    """
    Ziskava obsah zo suboru ktory sa preda v argumente.
    Vracia pole, kazdy item je riadok v subore
    """
    items_to_return = []
    fh = None
    try:
        for line in open(filename, mode="r", encoding="utf8"):
            items_to_return.append(line.rstrip())
    except EnvironmentError as err:
        print("CHYBA: nemozem nacitat {0}: {1}".format(filename, err))
    finally:
        if fh is not None:
            fh.close()
    return items_to_return
    
def print_lines(lines):
    """
    Vypise po riadkoch argument, ktory by mal byt pole.
    Cisluje od jedna
    """
    if not lines:
        print('-- v zozname nie su ziadne prvky --')
    else:
        dlzka_riadku = 1 if len(lines) < 10 else 2 if len(lines) < 100 else 3
        for index, line in enumerate(lines):
            print("{0:{dlzka_riadku}}. {line}".format(index+1, **locals()))
    print()

def get_string(message, name="string", default=None, minimum_length=0, maximum_length=80):
	message += ": " if default is None else " [{0}]: ".format(default)
	while True:
		try:
			line = input(message)
			if not line:
				if default is not None:
					return default
				if minimum_length == 0:
					return ""
				else:
					raise ValueError("{0} nemoze byt prazdne".format(name))
			if not (minimum_length <= len(line) <= maximum_length):
				raise ValueError("{name} musi mat najmenej {minium_length} a najviac {maximum_length} znakov".format(**locals()))
			return line
		except ValueError as err:
			print("ERROR", err)

def get_integer(message, name="integer", default=None, minimum=0,maximum=100, allow_zero=True):
	
	class RangeError(Exception): 
		pass

	message += ': ' if default is None else " [{0}]: ".format(default)
	while True:
		try:
			line = input(message)
			if not line and default is not None:
				return default
			i = int(line)
			if i == 0:
				if allow_zero:
					return i
				else:
					raise RangeError("{0} nemoze byt nula!".format(name))
			if not (minimum <= i <= maximum):
				raise RangeError("{name} musi byt medzi {minimum} a {maximum}"
					"vratane {0}".format(" (alebo 0)" if allow_zero else "", **locals()))
			return i
		except RangeError as err:
			print('ERROR', err)
		except ValueError as err:
			print("ERROR {0} musi byt cislica".format(name))

main()