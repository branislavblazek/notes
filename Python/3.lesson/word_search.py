#VERZIA 1: hlada na jednoslovnych riadkoch
import sys

if len(sys.argv) < 2:
    print('pouzitie: {0} slovo subor1 [subor2 ...suborN]'.format(sys.argv[0]))
    sys.exit()

word = sys.argv[1]
count = 0
results = {}
for filename in sys.argv[2:]:
    for pos, res in enumerate(open(filename), start=1):
        if word in res:
            results.setdefault(filename, dict())[res[:-1]] = pos
            results[filename]['count'] = results[filename].get('count', 0) + 1
            count += 1
    
for file, value in results.items():
    print('Subor {0} obsahuje {1} vysledk(y/ov)'.format(file, value['count']))
    results[file].pop('count')
    for key, item in value.items():
        print('Na riadku {0} sa nachadza: {1}'.format(item, key))
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
