import string
import sys
import collections

words = collections.defaultdict(int)
strip = string.whitespace + string.punctuation + string.digits + "\"'"
for filename in sys.argv[1:]:
    for line in open(filename):
        for word in line.lower().split():
            word = word.strip(strip)
            if len(word) > 2:
                words[word] += 1

def value(x):
    return words[x]

for word in sorted(words.items(), key=value, reverse=True):
    print('{0} sa vyskytuje {1}krat'.format(word, words[word]))

#def value(x):
#    return x[1]
#
#for word,count in sorted(words.items(), key=value):
#    print('{0} sa vyskytuje {1}krat'.format(word, count))
