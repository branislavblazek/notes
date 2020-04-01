vrcholy, hrany = map(int, input().split())
graf = [[] for _ in range(vrcholy)]

for i in range(hrany):
    a, b = map(int, input().split())
    graf[a].append(b)
    graf[b].append(a)

for i in range(vrcholy):
    graf[i].sort()
    print(*graf[i], sep=' ')