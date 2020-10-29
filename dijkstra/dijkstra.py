from queue import PriorityQueue

pocet_vrcholov, pocet_hran = map(int, input().split())
matica_susedov = [[] for _ in range(pocet_vrcholov)]

for _ in range(pocet_hran):
    u, v, cena = map(int, input().split())
    matica_susedov[u].append((cena, v))
    matica_susedov[v].append((cena, u))

start, koniec = map(int, input().split())
halda = PriorityQueue()
halda.put((0, start))
navstiveny = [-1] * pocet_vrcholov

while not halda.empty():
    cena, vrchol = halda.get()
    if vrchol == koniec:
        print(cena)
        exit(0)

    if navstiveny[vrchol] != -1:
        continue

    navstiveny[vrchol] = cena

    for cena_hrany, sused in matica_susedov[vrchol]:
        if navstiveny[sused] == -1:
            halda.put((cena + cena_hrany, sused))

print(-1)