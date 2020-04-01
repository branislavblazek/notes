def umocni(a, b, mod):
    res = 1
    while b > 0:
        if b % 2 == 1:
            res = (res * a) % mod
        a = (a * a) % mod
        b = b // 2
    return res

def inverzny_prvok(a, p):
    return umocni(a, p-2, p)

inverzny_prvok(2, 7)
>>> 4