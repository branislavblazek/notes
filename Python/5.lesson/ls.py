import optparse
import os
import datetime

def get_args():
    """
    Funkcia ziska z prikazove riadku argumenty na chod programu.
    Vracia argumenty a cesty

    Ziskava ci zobrazit skryte subory, zobrzit datum a cas poslednej upravy,
    v akom poradi sa maju zobrazit vysledky, sposob prehladavania a ci zobrazit vlelkost suborov.
    Vyuzitie modulu optparse
    """
    usage = "usage: %prog [options] [path1 [path2 [... pathN]]] \n\nPaths are optional, if they are not, program will use the actual folder."
    parser = optparse.OptionParser(usage=usage)
    order_choice = ('name', 'n', 'modified', 'm', 'size', 's')
    parser.add_option('-H', '--hidden', dest='hidden', action='store_true', help='show hidden files [default: %default]')
    parser.add_option('-m', '--modified', dest='modified', action='store_true', help='show date and time of last modification [default: %default]')
    parser.add_option('-o', '--order', dest='order', type='choice', choices=order_choice, help='order an output by (' + " ".join(order_choice) + ') [default: %default]')
    parser.add_option('-r', '--recursive', dest='recursive', action='store_true', help='coming down recursive to subfolders [default: %default]')
    parser.add_option('-s', '--sizes', dest='sizes', action='store_true', help='show sizes [default: %default]')

    parser.set_defaults(hidden=False, modified=False, order='name', recursive=False, sizes=False)
    opts, args = parser.parse_args()
    return opts, args

def print_data(data_dirs, data_files, opts):
    """
    Funkcia na vypisanie riadkov
    """
    get_time = lambda time_x: datetime.datetime.fromtimestamp(time_x).strftime("%Y-%m-%d %H:%M:%S")

    for item in data_dirs:
        #spracovanie casu
        time = None
        #spracovanie velkosti
        size = None
        #spracovanie nazvu

        print("{0:>20}{1:>15}{2}".format(time if time else '', size if size else '', item['path']))

    for item in data_files:
        time = None
        if opts.modified:
            time = get_time(item['modified']) + ' '

        size = None
        if opts.sizes:
            size = str(item['size']) + ' '

        print("{0:>20}{1:>15}{2}".format(time if time else '', size if size else '', item['path']))

    len_files = 'any' if len(data_files) == 0 else str(len(data_files)) + ' files' if len(data_files) != 1 else ' file'
    len_dirs = 'any' if len(data_dirs) == 0 else str(len(data_dirs)) + ' folders' if len(data_dirs) != 1 else ' folder'
    print(len_files + ', ' + len_dirs)

def get_files(path, recursive, hidden):
    """
    Funkcia vrati obsah priecinka

    Prvy argument je cesta [string]
    Druhy argument je vlastnost prehladavanie [string]
    Treti argument je ci sa maju zobrazit aj skryte subory [bool]
    """
    #vetvenie: pokial je recursive False alebo True
    if not os.path.exists(path):
        return False
    dirs_data = []
    files_data = []
    if not recursive:
        for file in os.listdir(path):
            #kontrola ci pridat aj hidden
            if not hidden and file.startswith('.'):
                continue
            ###chceme len info o suboroch
            fullname = os.path.join(path, file)
            data = {}
            data['type'] = 'file' if os.path.isfile(fullname) else 'dir'
            data['path'] = file + ('' if os.path.isfile(fullname) else '/')
            data['size'] = os.path.getsize(fullname)
            data['modified'] = os.path.getmtime(fullname)
            if os.path.isfile(fullname):
                files_data.append(data)
            else:
                dirs_data.append(data)
    else:
        pass

    return files_data, dirs_data

def main():
    """
    Hlavna funkcia
    """
    #ziskam argumenty
    opts, args = get_args()
    #prejdem kazdu jednu path, z kazdej ziskam data
    if not args:
        args.append(os.getcwd())

    data_files = []
    data_dirs = []

    for path in args:
        some_data = get_files(path, opts.recursive, opts.hidden)
        data_files += some_data[0]
        data_dirs += some_data[1]

    #zosortuj data
    #akym sposobom
    if opts.order == 's':
        opts.order = 'size'
    elif opts.order == 'n' or opts.order == 'name':
        opts.order = 'path'
    elif opts.order == 'm':
        opts.order = 'modified'

    sorted_items_files = sorted(data_files, key=lambda x: x[opts.order])
    sorted_items_dirs = sorted(data_dirs, key=lambda x: x[opts.order])

    print_data(sorted_items_dirs, sorted_items_files, opts)

if __name__ == "__main__":
    main()
