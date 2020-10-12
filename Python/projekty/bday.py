import os
import random
import time

data = [
    ["  ***  "," *   * ","*     *","*     *","*     *"," *   * ","  ***  "],
    [" * ", "** ", " * ", " * ", " * ", " * ", "***"],
    [" *** ", "*   *", "*  * ", "  *  ", " *   ", "*    ", "*****"],
    [" *** ", "*   *", "    *", "  ** ", "    *", "*   *", " *** "],
    ["   *  ", "  **  ", " * *  ", "*  *  ", "******", "   *  ","   *  "],
    ["*****", "*    ", "*    ", " *** ", "    *", "*   *", " *** "],
    [" *** ", "*    ", "*    ", "**** ", "*   *", "*   *", " *** "],
    ["*****", "    *", "   * ", "  *  ", " *   ", "*    ", "*    "],
    [" *** ", "*   *", "*   *", " *** ", "*   *", "*   *", " *** "],
    [" ****", "*   *", "*   *", " ****", "    *", "    *", "    *"]
]

def print_normal(text, ignor=1):
    global space
    space = ' '
    return text

def print_znak_rev(text, znak):
    znak = str(znak)
    global space
    space = znak
    new_text = ''
    for i in text:
        if i == '*':
            new_text += ' '
        else:
            new_text += znak
    return new_text

def print_cislo(text, cislo):
    cislo = str(cislo)
    new_text = ''
    for i in text:
        if i == '*':
            new_text += cislo
        else:
            new_text += ' '
    return new_text

vek = 17
space = ' '
velkost = 0
time_delay = 0.1

def vypis(velkost):
    for i in range(7):
        line = velkost
        under_line = ''
        if i == 0: print(velkost, end='')
        for column in range(len(str(vek))):
            cislo = int(str(vek)[column])
            if column == 0: line += str(cislo)
            line += print_znak_rev(data[cislo][i], cislo)
            if column == 1: line += str(cislo)
            line += space
            if i == 0: print(str(cislo) * (len(data[cislo][i])+2), end='')
            if i == 6: under_line += str(cislo) * (len(data[cislo][i])+2)
        if i == 0: 
            print('', end='\n')
            time.sleep(time_delay)
        print(line)
        if i == 6: print(velkost + under_line)
        time.sleep(time_delay)

for i in range(1000):
    x = random.randint(0, 100) * " "
    vypis(x)
    x = random.randint(0, 100) * " "
    sprava = ['Vsetko najlepsie!', 'Happy Birhday!', 'VSETKO NAJLEPSIE!', 'vela stastia!']
    x = random.randint(0, 100) * " "
    print(x + random.choice(sprava))
    time.sleep(time_delay)