import sys
import string

if len(sys.argv) < 2:
    print('pouzitie: {0} slovo subor1 [subor2 ...suboorN]'.format(sys.argv[0]))

results = {}
key = sys.argv[1].lower()
strip = string.punctuation + string.whitespace + string.digits + "\"'"

for filename in sys.argv[2:]:
    for pos, line in enumerate(open(filename), start=1):
        words = line.split()
        for word in words:
            word = word.lower().strip(strip)
            if key in word:
                results.setdefault(filename, dict())
                results[filename]['__count__'] = results[filename].get('__count__', 0) + 1
                results[filename][word] = results[filename].get(word, 0) + 1
            
                        
for file, values in results.items():
    print('V subore {0} sa slovo {1} nachadza {2}-krat'.format(file, key, values['__count__']))
    values.pop('__count__')
    for value, count in values.items():
        print('Slovo {} sa nachadza {}-krat'.format(value, count))
