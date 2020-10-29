class Queue:
    def __init__(self):
        self.n = 100000
        self.queue = [None]*self.n
        self.first_pointer = 0
        self.k = 0
    
    def put(self, item):
        if self.k < self.n:
            self.queue[(self.first_pointer + self.k) % self.n] = item
            self.k += 1

    def get(self):
        if self.k > 0:
            value = self.queue[self.first_pointer]
            self.first_pointer = (self.first_pointer + 1) % self.n
            self.k -= 1
            return value
        else:
            return False

vrcholy, hrany = map(int, input().split())
graf = [[] for _ in range(vrcholy)]

for i in range(hrany):
    a, b = [int(i) - 1 for i in input().split(' ')]
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
q = Queue()
q.put(0)

while q.k > 0:
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