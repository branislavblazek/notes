try:
    #x = int('25')
    x = int('ahoj')
except ValueError as err:
    print('chyba pri premenene na int', err)
else:
    print('zmenene na int')
finally:
    print('prebehlo vsetko')
