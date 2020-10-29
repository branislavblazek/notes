import queue

vrcholy, hrany = map(int, input().split())

graf = [[] for _ in range(vrcholy)]

for i in range(hrany):
    a, b = [int(i) - 1 for i in input().split(' ')]
    graf[a].append(b)
    graf[b].append(a)

odkial = int(input()) - 1

class Vertex:
    def __init__(self, neighbours):
        self.neighbours = neighbours
        self.distance = -1
        self.seen = False

vrcholy = []
for udaje in graf:
    vrcholy.append(Vertex(udaje))

vrcholy[odkial].distance = 0
vrcholy[odkial].seen = True
q = queue.Queue()
q.put(odkial)

result = []

while q.qsize() > 0:
    v = q.get()
    for idx in vrcholy[v].neighbours:
        if vrcholy[idx].seen:
            continue
        
        vrcholy[idx].distance = vrcholy[v].distance + 1
        vrcholy[idx].seen = True
        
        if vrcholy[idx].distance == 2:
            result.append(idx+1)
        
        q.put(idx)

result.sort()
if not result:
    print(-1)
else:
    print('\n'.join(map(str, result)))