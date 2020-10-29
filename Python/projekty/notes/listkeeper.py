#!/usr/bin/python3
import os

NAZOV = '\n__Strazca zoznamu__\n'
CON_ENTER = 'Pre pokracovanie stlacte Enter...'

def main():
    #tu su subory
    items_in_file = []
    #nacitaj subory
    filename, items_in_file = choose_file()
    if not filename:
        print('Program ukonceny...')
        return

def choose_file():
    """
    Funckia vrati zoznam dostupnych suborov .lst v adresary.

    Pkial nie su ziadne, vytvori sa novy.
    Inak sa vypisu nazvy suborov.
    Uzivatel moze zvolit cislu suboru,
    alebo 0 pre novy.
    """
    create_new = False
    print(NAZOV)
    #ziskaj subory konciace .lst
    files = [x for x in os.listdir('.') if x.endswith('.lst')]
    if not files:
        create_new = True

    if not create_new:
        print_lines(files)
        index_file = get_integer('Zvolte cislo suboru (alebo 0 pre vytvorenie noveho)', 'integer')
        #pokial sa zvoli 0
        if index_file == 0:
            create_new = True
        else:
            #ziskaj nazov a jeho obsah
            filename = files[index_file-1]
            items_in_file = load_list(filename)
    if create_new:
        filename = get_string('Zadajte nazov suboru', 'filename')
        if not filename.endswith('.lst'):
            filename += '.lst'
        items_in_file = []

    return filename, items_in_file

def print_lines(lines):
    if not lines:
        print('--- V zozname nie su ziadne prvky ---')
    else:
        dlzka = 1 if len(lines) < 10 else 2 if len(lines) < 100 else 3
        for idx, value in enumerate(lines):
            print("{0:{dlzka}}. {value}".format(idx+1, **locals()))


    print()

def load_list(filename):
    """
    Vracia obsah subora
    """
    fh = None
    items_to_return = []
    try:
        for value in open(filename, mode='r', encoding='utf8'):
            items_to_return.append(value.rstrip())
    except EnvironmentError as err:
        print('ERROR nemozem otvorit subor {0}: {1}'.format(filename, err))
    finally:
        if fh is not None:
            fh.close()

    return items_to_return

def get_integer(message, name='integer', default=None, minimum=0, maximum=100, allow_zero=True):
    class RangeError:
        pass

    message += ': ' if default == None else " [{0}]: ".format(default)
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
                    raise RangeError('{0} nemoze byt nula!'.format(name))
            if not (minimum <= i <= maximum):
                raise RangeError('{0} musi byt vacsie ako {1} a mensie ako {2]}'.foramt(name, minimum, maximum))
            return i
        except RangeError as err:
            print('ERROR', err)
        except ValueError as err:
            print('ERROR {0} musi byt cislo!'.format(name))

def get_string(message, name='string', default=None, minimum_len=0, maximum_len=80):
    message += ': ' if default is None else ' [{0}]: '.format(default)
    while True:
        try:
            line = input(message)
            if not line:
                if default is not None:
                    return default
                if minimum_len <= 0:
                    return ""
                else:
                    raise ValueError('{0} nemoze byt prazdny retazec!'.format(name))
                return line
            if not (minimum_len <= len(line) <= maximum_len):
                raise ValueError('{0} musi mat viac ako {1} znakov a menej ako {2} znakov.'.format(name, minimum_len, maximum_len))
            return line
        except ValueError as err:
            print('ERROR', err)
