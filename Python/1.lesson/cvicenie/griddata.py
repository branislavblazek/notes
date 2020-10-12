import random

def get_int(msg, minimum, default):
    while True:
        try:
            line = input()
            if not line and default is not None:
                return default
            i = int(line)
            if i < minimum:
                print('Hodnota musí byť väčšia ako ', default)
            else:
                return i
        except ValueError as err:
            print(err)

riadky = get_int('riadkov: ', 1, None)
stlpce = get_int('stlpcov: ', 1, None)
minimum = get_int('minimum: ', -10000, 0)

default = 1000
if default < minimum:
    default = 2 * minimum
maximum = get_int('maximum: ', minimum, default)

riadok = 0
while riadok < riadky:
    line = ""
    stlpec = 0
    while stlpec < stlpce:
        i = random.randint(minimum, maximum)
        s = str(i)
        while len(s) < 6:
            s = " " + s
        line += s
        stlpec += 1
    print(line)
    riadok += 1
