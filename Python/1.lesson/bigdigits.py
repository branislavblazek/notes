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
    digits = sys.argv[1]
    row = 0
    while row < 7:
        column = 0
        line = ""
        while column < len(str(digits)):
            number = int(str(digits)[column])
            #print(number, row)
            line += data[number][row]
            line += "  "
            column += 1
        print(line)
        row += 1
except IndexError:
    print('Použitie: python bigdigits.py <cislo>')
    
