from collections import deque

riadky, symboly = map(int, input().split())

table = []

for _ in range(riadky):
    line = []
    for value in input():
        if value == '.':
            line.append(-1)
        elif value == 'S':
            start = [len(table), len(line)]
            line.append(0)
        else:
            line.append(value)
    
    table.append(line)

q = deque()
q.append(start)

dX = [1,0,-1,0]
dY = [0,1,0,-1]
done = False

while len(q) > 0:
    v = q.popleft()
    
    for idx_sused in range(len(dX)):
        x = v[0]
        y = v[1]
        sused_x = x + dX[idx_sused]
        sused_y = y + dY[idx_sused]

        if sused_x < 0 or sused_x >= riadky or sused_y < 0 or sused_y >= symboly:
            continue

        novy = table[sused_x][sused_y]
        stary = table[x][y]

        if novy == -1:
            table[sused_x][sused_y] = stary + 1
        elif novy == 'F':
            print(stary+1)
            done = True
            break
        else:
            continue
        q.append([sused_x, sused_y])
    if done:
        break
if not done:
    print(-1)