import sys

def value(x):
    return lines[x]

lines = dict()
for line in open(sys.argv[1]):
    line = line.strip()
    if line:
        if '(' in line:
            l = line.index('(')
            r = line.index(')')
            if ',' in line[l:r]:
                r = line.index(',')
        else:
            continue
        res =  line[l+1:r].replace('str. ', '')
        try:
            res = int(res)
            lines[line] = res
        except ValueError:
            continue

fout = open('x.txt', 'w')
for word in sorted(lines.items(), key=value, reverse=True):
    fout.write(word + ' ' + lines[word] + '\n')
    
