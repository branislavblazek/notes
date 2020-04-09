n, hodiny = [int(i) for i in input().split(' ')]
data = [int(i) for i in input().split(' ')]
prefix = [0]
for x in data:
    prefix.append(prefix[-1] + x)
pocet = {}
odpoved = 0
for x in prefix[:hodiny + 1]:
    pocet[x] = pocet[x] + 1 if x in pocet else 1
odpoved = pocet[prefix[0]] - 1
for idx in range(1, len(prefix) - hodiny):
    pocet[prefix[idx-1]] -= 1
    pocet[prefix[idx + hodiny]] = pocet[prefix[idx + hodiny]] + 1 if prefix[idx + hodiny] in pocet else 1
    odpoved += pocet[prefix[idx]] - 1
pocet[prefix[len(prefix) - hodiny -1]] -= 1
for x in pocet.keys():
    odpoved += (pocet[x]*(pocet[x]-1)//2)
print(odpoved)