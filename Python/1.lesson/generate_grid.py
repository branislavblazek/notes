import random

#fcia vráti buď prednastavenu hodnotu alebo cislo
def get_int(msg, minimum, default):
    try:
        while True:
            line = input(msg)
            if not line and default is not None:
                return default
            i = int(line)
            if i < minimum:
                print('Hodnota nemôže byť menšia ako ', minimum)
            else:
                return i
    except ValueError as err:
        print(err)

rows = get_int('riadkov: ', 1, None)
columns = get_int('stĺpcov: ', 1, None)
minimum = get_int('minimum:(alebo Enter pre 0) ', -100000, 0)

default = 1000
if default < minimum:
    default = 2 * minimum
maximum = get_int('maximum:(alebo Enter pre ' + str(default) + ') ', minimum, default)

row = 0
while row < rows:
    line = ""
    column = 0
    while column < columns:
        i = random.randint(minimum, maximum)
        s = str(i)
        while len(s) < 5:
            s = " " + s
        line += s
        column += 1
    print(line)
    row += 1
