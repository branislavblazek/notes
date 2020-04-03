from queue import PriorityQueue

class Vertex:
    def __init__(self, index):
        self.index = index
        self.susedia = {}
        self.seen = -1

pocet_vrcholov, pocet_hran = map(int, input().split())
vrcholy = [Vertex(index) for index in range(pocet_vrcholov)]

for _ in range(pocet_hran):
    u, v, cena = map(int, input().split())
    u -= 1
    v -= 1
    vrcholy[u].susedia[v] = cena
    vrcholy[v].susedia[u] = cena

start, koniec = map(int, input().split())
start -= 1
koniec -= 1
halda = PriorityQueue()
halda.put((0, start))

while not halda.empty():
    cena, index = halda.get()
    vrchol = vrcholy[index]
    if vrchol.index == koniec:
        print(cena)
        exit(0)

    if vrchol.seen != -1:
        continue

    vrchol.seen = cena

    for sused, cena_hrany in vrchol.susedia.items():
        if vrcholy[sused].seen == -1:
            halda.put((cena + cena_hrany, sused))

print(-1)
