import sys
import copy

def get_file(filename):
    try:
        file = open(filename)
        return file
    except FileNotFoundError:
        print('The file with words doesn\'t exists!')
        return False
  
def get_words(length, start, filename):
    possible = list()
    for line in get_file(filename):
        word = line.strip()
        if len(word) == int(length) and word.startswith(start):
            possible.append(word)

    return possible

def main():
    if len(sys.argv) < 2 or sys.argv[1] in {'-h', '--help', 'pomoc'}:
        print('pouzitie: {} dlzka_zaciatok [dlzka_zaciatok ...]'.format(sys.argv[0]))

    filein = 'english_words.txt'
    fileout = 'english_words_result.txt'
    file = get_file(filein)
    if not file:
        return False

    result = []
    
    for hint in sys.argv[1:]:
        new_result = []
        hint = hint.split('_')
        words = get_words(hint[0], hint[1], filein)
        if len(result) == 0:
            result = words
        else:
            for base in result:
                for word in words:
                    new_result.append(base + ' ' + word)
            result = new_result

    fout = open(fileout, "w")
    for res in result:
        fout.write(res + '\n')
    
main()
