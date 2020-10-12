import sys

Zero = ["  ***  "," *   * ","*     *","*     *","*     *"," *   * ","  ***  "]
One = [" * ", "** ", " * ", " * ", " * ", " * ", "***"]
Two = [" *** ", "*   *", "*  * ", "  *  ", " *   ", "*    ", "*****"]
Three = [" *** ", "*   *", "    *", "  ** ", "    *", "*   *", " *** "]
Four = ["   *  ", "  **  ", " * *  ", "*  *  ", "******", "   *  ",
        "   *  "]
Five = ["*****", "*    ", "*    ", " *** ", "    *", "*   *", " *** "]
Six = [" *** ", "*    ", "*    ", "**** ", "*   *", "*   *", " *** "]
Seven = ["*****", "    *", "   * ", "  *  ", " *   ", "*    ", "*    "]
Eight = [" *** ", "*   *", "*   *", " *** ", "*   *", "*   *", " *** "]
Nine = [" ****", "*   *", "*   *", " ****", "    *", "    *", "    *"]

Digits = [Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine]

try:
    digit = sys.argv[1]
    row = 0
    while row < 7:
        line = ""
        column = 0
        while column < len(digit):
            odkaz = int(digit[column])
            Digit = Digits[odkaz][row]
            string = ""
            for x in Digits[odkaz][row]:
                if x == "*":
                    string += str(odkaz)
                else:
                    string += " "
            line += string + "  "
            column += 1
        print(line)
        row += 1
except IndexError:
    print('použitie: python bigdigits.py 123456789')
except ValueError as err:
    print(err)
