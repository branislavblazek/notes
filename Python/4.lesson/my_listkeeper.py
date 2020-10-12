#!/usr/bin/python3
import os

NAZOV = '\n__Strazca zoznamu__\n'
CON_ENTER = 'Pre pokracovanie stlacte Enter...'

def main():
    new_changes = False
    #tu su subory
    items_from_file = []
    #nacitaj obsah priecinka
    filename, items_from_file = choose_file()
    if not filename:
        print('ukoncujem...')
        return
    
    while True:
        print(NAZOV)
        print_lines(items_from_file)

        now_to_do = get_choice(items_from_file, new_changes)
        #pridat
        if now_to_do == 'p':
            new_changes = add_item(items_from_file, new_changes)
        elif now_to_do == 'v':
            new_changes = del_item(items_from_file, new_changes)
        elif now_to_do == 'u':
            new_changes = save_item(filename, items_from_file)
        elif now_to_do == 'k':
            if (new_changes and get_string('Chcete ulozit neulozene data? (a/n)', default='a').lower() in ('a', "ano")):
                save_item(filename, items_from_file, False)
            break


def save_item(filename, items_from_file, contin=True):
    fh = None
    try:
        fh = open(filename, mode="w", encoding="utf8")
        fh.write("\n".join(items_from_file))
        fh.write('\n')
    except EnvironmentError as err:
        print('ERROR: nemozem ulozit {0}: {1}'.format(filename, err))
        return True
    else:
        print('Zoznam bol ulozeny do {0}, celkom ulozenych prvkov: {1}'.format(filename, len(items_from_file)))
        if contin:
            input(CON_ENTER)
        return False
    finally:
        if fh is not None:
            fh.close()

def del_item(item, changes):
    index = get_integer('Vymazat prvok (alebo 0 pre zrusenie)')
    if index == 0:
        return changes
    else:
        del item[index-1]
        return True

def add_item(items, changes):
    n_item = get_string('Pridat prvok')
    if n_item:
        items.append(n_item)
        items.sort(key=str.lower)
        return True
    return False

def get_choice(items, changes):
    if not items:
        message = "Pridat[p]    Koniec[k]"
        valid_input = ('pk')
    else:
        if changes:
            message = "Pridat[p]    Vymazat[v]    Ulozit[u]    Koniec[k]"
            valid_input = ('pvuk')
        else:
            message = "Pridat[p]    Vymazat[v]    Koniec[k]"
            valid_input = ('pvk')
    
    user_wants = get_string(message, default='p').lower()
    if user_wants not in valid_input:
        print('ERROR: neplatna volba, zadajte jednu z tychto moznosti: {0}'.format(valid_input))
        input(CON_ENTER)
    else:
        return user_wants.lower()

def choose_file():
    """
    funckia vrati zoznam suborov v priecinku.
    pokial sa nic nenachadza v aktualnom priecinku, vytvara novy subor, 
    pokial tam uz nieco je, da userovy na vyber ktory subor chce citat. 
    pokial user da 0, vytovri sa novy
    pokial user stlaci ine cislo, precita sa ten subor
    """
    create_new = False
    print(NAZOV)
    files = [x for x in os.listdir('.') if x.endswith('.lst')]
    if not files:
        create_new = True

    if not create_new:
        print_lines(files)
        inpt_value = get_integer('Zvolte cislo suboru ( alebo 0 pre vytvorenie noveho)', 'integer')
        if inpt_value == 0:
            create_new = True
        else:
            filename = files[inpt_value-1]
            items_in_file = get_lines(filename)
    if create_new:
        filename = input('meno suboru: ')
        if not filename.endswith('.lst'):
            filename += '.lst'
        items_in_file = []

    return filename, items_in_file
        
def get_lines(filename):
    """
    Vracia obsah subora, podla filename
    """
    fh = None
    items_to_return = []
    try:
        for value in open(filename, mode='r', encoding='utf8'):
            items_to_return.append(value.rstrip())
    except EnvironmentError as err:
        print("CHYBA: nemozem otvorit subor {filename}: {err}".format(**locals()))
    finally:
        if fh is not None:
            fh.close()

    return items_to_return
    
def print_lines(lines):
    if not lines:
        print('--- v zozname nie su ziadne prvky ---')
    else:
        dlzka = 1 if len(lines) < 10 else 2 if len(lines) < 100 else 3
        for idx, value in enumerate(lines):
            print("{0:{dlzka}}. {value}".format(idx+1, **locals()))
    print()

def get_integer(message, name='integer', default=None, minimum=0, maximum=100, allow_zero=True):
    class RangeError:
        pass
    
    message += ": " if default == None else " [{0}]: ".format(default)
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
                raise RangeError("{name} musi byt medzi {minimum} a {maimum} vratane {0}".format(" (alebo 0)" if allow_zero else "", **locals()))
            return i
        except RangeError as err:
            print('ERROR', err)
        except ValueError as err:
            print('ERROR {0} mus byt cislica!'.format(name))

def get_string(message, name='string', default=None, minimum_len=0, maximum_len=80):
    message += ": " if default is None else " [{0}]: ".format(default)
    while True:
        try:
            line = input(message)
            if not line:
                if default is not None:
                    return default
                if minimum_len == 0:
                    return ""
                else:
                    raise ValueError("{0} nemoze byt prazdny retazec".format(name))
                return line
            if not (minimum_len <= len(line) <= maximum_len):
                raise ValueError("{0} musi mat najmenej {minumum_len} a najviac {maximum_len} znakov".format(name, **locals()))
            return line
        except ValueError as err:
            print("ERROR", err)
    

main()