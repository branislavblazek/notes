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

def cislo(value):
    try:
        value = str(value)
        row = 0
        while row < 7:
            line = ""
            column = 0
            length = len(value)#pre zistenie dlzky cisla musi byt cislo string
            while column < length:
                number = value[column]
                line += data[int(number)][row] + "  "
                column += 1
            print(line)
            row += 1
    except ValueError:
        print('použitie: python testing.py <cislo>')
cislo(sys.argv[1])
