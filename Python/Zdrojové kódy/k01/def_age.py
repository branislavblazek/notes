def get_int(msg):
    while True:
        try:
            i = int(input(msg))
            return i
        except ValueError as error:
            print('Hodnota musí byť integer!')

age = get_int("Zadajte svoj vek: ")
print(age)
