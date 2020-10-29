vrcholy, hrany = map(int, input().split())
matrix = [[0]*vrcholy for i in range(vrcholy)]

for i in range(hrany):
    a, b = map(int, input().split())
    matrix[a][b] = matrix[b][a] = 1

for i in range(vrcholy):
    print(*matrix[i], sep=' ')