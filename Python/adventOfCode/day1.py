file = open('day1input.txt', 'r')

total = 0

for line in file:
    num = int(line)
    fuel = 0
    while (num // 3) - 2 > 0:
        num = (num // 3) - 2
        fuel += num
    total += fuel


print(total)
