import string
import sys

if len(sys.argv) < 2:
    print('pouzitie: {} file1 [file2 ...fileN]'.format(sys.argv[0]))

words = {}
strip = string.whitespace + string.punctuation + string.digits + "\"'"
for filename in sys.argv[1:]:
    for line in open(filename):
        for word in line.lower().split():
            word = word.strip(strip)
            if len(word) > 2:
                words[word] = words.get(word, 0) + 1

for word in sorted(words.values()):
    print('slovo {} sa vyskytuje {}-krat'.format(word, words[word]))
