from random import choice

def get_forenames_surnames():
    forenames = []
    surnames = []
    for filename, names in (('forenames.txt', forenames),('surnames.txt', surnames)):
        for name in open(filename):
            names.append(name.rstrip())
    return forenames, surnames

forenames, surnames = get_forenames_surnames()
fh = open('test-names1.txt', "w", encoding="utf8")
for _ in range(100):
    line = '{} {}\n'.format(choice(surnames), choice(forenames))
    fh.write(line)
