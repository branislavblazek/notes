import queue

class Vertex:
    def __init__(self, neighbours):
        self.neighbours = neighbours
        self.distance = -1
        self.seen = False

graf = [[1,2], [0,5], [0,4,3], [2,4], [2,3,5,6,7], [1,4,6], [4,5,8], [4,8], [6,7]]
vrcholy = [Vertex(udaje) for udaje in graf]
start = 0
end = 8
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