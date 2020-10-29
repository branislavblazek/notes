import random

def get_forenames_surnames():
    forenames = []
    surnames = []
    for filename, names in (('forenames.txt', forenames),('surnames.txt', surnames)):
        for name in open(filename):
            names.append(name.rstrip())
    return forenames, surnames

forenames, surnames = get_forenames_surnames()
fh = open('test-names2.txt', "w", encoding="utf8")

limit = 100
years = list(range(1970, 2019)) * 3
for year, forename, surname in zip(
    random.sample(years, limit),
    random.sample(forenames, limit),
    random.sample(surnames, limit)):
    name = '{} {}'.format(forename, surname)
    fh.write('{0:.<25}.{1}\n'.format(name, year))
