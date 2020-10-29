import random
def rndm(co):
    if co == "cislo":
        return random.randint(1,100)
    elif co == 'slovo':
        return random.choice(['ahoj', 'svet', 'nazdar', 'hello'])
print(rndm('cislo'))
print(rndm('slovo'))
