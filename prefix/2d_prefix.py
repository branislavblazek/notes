r, c = [int(i) for i in input().split(' ')]
prefix = []
for _ in range(r+1):
    prefix.append([0])

for _ in range(c):
    prefix[0].append(0)

data = []

for y in range(r):
    inpt = [int(i) for i in input().split(' ')]
    data.append(inpt)

for y in range(1, r+1):
    for x in range(1, c+1):
        prefix[y].append(prefix[y][x-1] + prefix[y-1][x] + data[y-1][x-1] - prefix[y-1][x-1])

otazok = int(input())
res = []
for _ in range(otazok):
    y_1, x_1, y_2, x_2 = [int(i)-1 for i in input().split(' ')]
    res.append(prefix[y_2+1][x_2+1] - prefix[y_2+1][x_1] - prefix[y_1][x_2+1] + prefix[y_1][x_1])