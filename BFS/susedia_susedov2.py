import queue

vrcholy, hrany = map(int, input().split())

struck = [[-1,False,[]] for _ in range(vrcholy)]

for i in range(hrany):
    a, b = [int(i) - 1 for i in input().split(' ')]
    struck[a][2].append(b)
    struck[b][2].append(a)

prvy = int(input()) - 1

q = queue.Queue()

struck[prvy][0] = 0
struck[prvy][1] = True

q.put(prvy)

data = []

while q.qsize() > 0:
    v = q.get()
    for x in struck[v][2]:
        if struck[x][1]:
            continue
        
        struck[x][0] = struck[v][0] + 1
        struck[x][1] = True
        
        if struck[x][0] == 2:
            data.append(x+1)
        
        q.put(x)

data.sort()
if not data:
    print(-1)
else:
    print('\n'.join(map(str, data)))