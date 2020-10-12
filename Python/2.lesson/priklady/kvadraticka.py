import cmath
import math
import sys

#nejaky fix lebo vo windowsoch nefunguje SUPERSCRIPT
SQUARED = "\N{SUPERSCRIPT TWO}"
ARROW = "\N{RIGHTWARDS ARROW}"
if not sys.platform.startswith("linux"):
    SQUARED = "^2"
    ARROW = "->"

#bude prechadzat cyklus dokym uzivatel nezada flaot cislo (-9, 21, 0.5, 8.35),
#hodnotu nula povoli iba ked bude v allow_zero True
def get_float(msg, allow_zero):
    x = None
    while x is None:
        try:
            x = float(input(msg))
            if not allow_zero and abs(x) < sys.float_info.epsilon:
                print('nemozte zadata nulu')
                x = None
        except ValueError as err:
            print(err)
    return x

#prevezme vstupne hodnoty pre koeficienty
print('ax' + SQUARED + '+ bx + c = 0')
a = get_float('zadajte a: ', False)
b = get_float('zadajte b: ', True)
c = get_float('zadajte c: ', True)

#zacina pocitat
#kontrola diskriminanatu
#       (       ________  )
#       (-b ± \/b^2 - 4ac )
# x =   (---------------- )
#       (      2a         )
x1 = None
x2 = None
diskriminant = (b ** 2) - (4 * a * c)
if diskriminant == 0:
    x1 = -(b / (2 * a))
else:
    if diskriminant > 0:
        root = math.sqrt(diskriminant)
    else: #diskriminant < 0
        root = cmath.sqrt(diskriminant)
    x1 = (-b + root) / (2 * a)
    x2 = (-b - root) / (2 * a)

equation = ('{a}x{SQUARED} + {b}x + {c} = 0 {ARROW} x = {x1}'.format(**locals()))
if x2 is not None:
    equation += ' alebo x = {0}'.format(x2)
print(equation)
