import sys

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

try:
    digit = sys.argv[1]
    row = 0
    while row < 7:
        line = ""
        column = 0
        while column < len(str(digit)):
            number = int(str(digit)[column])
            star = data[number][row]
            #star obsahuje zmes medzier a hviezdiciek
            #nameisto toho ale chcem aby tam boli konkretne cislice
            i = 0
            to_ret = ""
            for i in star:
                if i == '*':
                    i = str(number)
                line += i
            line += ' '
            column += 1
        print(line)
        row += 1
except IndexError:
    print('použitie: python bigdigits2.py <cislo>')
