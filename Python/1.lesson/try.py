s = input("Zadajte celé číslo:")
try:
    i = int(s)
    print("Zadané platné celé číslo")
except ValueError as error:
    print(error)
