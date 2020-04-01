import queue

vrcholy, hrany = map(int, input().split())
graf = [[] for _ in range(vrcholy)]

for i in range(hrany):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graf[a].append(b)
    graf[b].append(a)

odkial, kam = map(int, input().split())
odkial -= 1
kam -= 1

class Vertex:
    def __init__(self, idnex, neighbours):
        self.neighbours = neighbours
        self.distance = -1
        self.index = index
        self.seen = False

vrcholy = []

for index, udaje in enumerate(graf):
    vrcholy.append(Vertex(index, udaje))

vrcholy[0].distance = 0
vrcholy[0].seen = True
q = queue.Queue()
q.put(0)

while q.qsize() > 0:
    v = vrcholy[q.get()]
    for idx in v.neighbours:
        sused = vrcholy[idx]
        if sused.seen:
            continue
        
        sused.distance = v.distance + 1
        sused.seen = True
        
        q.put(idx)

if vrcholy[kam].seen == False:
    print(-1)
else:
    print(vrcholy[kam].distance)