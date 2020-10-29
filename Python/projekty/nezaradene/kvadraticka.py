# Program for calculating kvadratic equation.
import sys
import math

def get_float(msg, allow_zero):
    # This will get float for equation.
    number = None
    while number is None:
        try:
            number = float(input(msg + ': '))
            if not allow_zero and abs(number) < sys.float_info.epsilon:
                number = None
        except ValueError:
            pass
    return number

a = get_float('zadajte koeficient pre a', False)
b = get_float('zadajte koeficient pre b', True)
c = get_float('zadajte koeficient pre c', True)

# Urci korene rovnice.
x1 = None
x2 = None
# Vypocita diskriminant.
D = (b ** 2) - 4 * a * c
# Spracuje ho.
if D == 0:
    x1 = -b / (2 * a)
elif D > 0:
    root = math.sqrt(D)
    x1 = (-b + root) / (2 * a)
    x2 = (-b - root) / (2 * a)
# Vyhodnoti vysledok
result = '{a}x^2 '.format(**locals())
if b != 0:
    b = int(b)
    result += '{b}x '.format(**locals())
if c != 0:
    c = int(c)
    result += '{c} '.format(**locals())

result += ' = 0 -> x = {x1}'.format(**locals())
if x2 is not None:
    result += ' or x = {x2}'.format(**locals())

print(result)
 
