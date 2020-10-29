import math
def generate_prime(start, size):
    num = start
    prime = []
    while len(prime) < size:
        if num > 1:
            isprime = True
            for x in range(2,math.ceil(math.sqrt(num))+1):
                if num % x == 0:
                    isprime = False
                    break
            if isprime:
                prime.append(num)
        num += 1
    return prime

def get_int(msg, minimum, default):
    while True:
        try:
            line = input()
            if not line and default is not None:
                return default
            i = int(line)
            if i < minimum:
                print()
            else:
                return i
        except ValueError as Err:
            print(Err)

def generate_grid(rows, columns, prvo):
    row = 0
    index = 0
    while row < rows:
        column = 0
        line = ""
        while column < columns:
            pr = str(prvo[index])
            while len(pr) < 15:
                pr = " " + pr
            line += pr
            index += 1
            column += 1
        print(line)
        row += 1

start = get_int('Zadajte prvé číslo', 0, 1)
riadky = get_int('Zadajte počet riadkov', 1, None)
stlpce = get_int('Zadajte počet stĺpcov', 1, None)

prvocisla = generate_prime(start, riadky*stlpce)
generate_grid(riadky, stlpce, prvocisla)

#10.000 vygeneruje za cas ~ 2:48 min
#100.000 vygeneruje za cas ~ 0:42 min v CMD

