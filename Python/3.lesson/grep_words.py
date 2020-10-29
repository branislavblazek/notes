import sys

if len(sys.argv) < 1:
    print('pouzitie: {0} slovo subor1 [subor2 ...suborN]'.format(sys.argv[0]))
    sys.exit()

word = sys.argv[1]
for filename in sys.argv[2:]:
    for pos, res in enumerate(open(filename), start=1):
        if word in res:
            print('{0}:{1}:{2}'.format(filename, pos, res))
