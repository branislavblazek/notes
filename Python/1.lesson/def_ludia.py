def pozdrav(meno, vek):
    val1 = str(meno)
    val2 = str(vek)
    return('Ahoj, volám sa ' + val1 + ' a mám ' + val2 + ' rokov')

data = [['Branislav', 16], ['Tomáš', 27], ['Adam', 18], ['Andrej', 35]]
for user in data:
    print(pozdrav(user[0], user[1]))
