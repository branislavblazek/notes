def get_file_object(filename):
    #vrati nazov suboru pokial existuje ten suvot, inak False
    try:
        file = open(filename)
        return file
    except FileNotFoundError:
        return False

def find_similiar_words(word, file):
    """
    najprv vyberie zo vstupu slova ktore sa lisia prave jednym pismemom od zaciatocenhi
    potom to spravi s tym co ma
    """
    def is_similiar_word(word, sim_word):
        """
        porovnava dve slova, pokial je 1. vstupne slovo rozlicne od 2.heho o prave jeden znak
        tak ho vrati, inak vrati False
        """
        length = len(word)
        same_letters = 0
        for index, letter in enumerate(word):
            if letter == sim_word[index]:
                same_letters += 1
        
        return True if same_letters == length - 1 else False
        #</is_similiar_word()>

    result = []
    for possible_word in file:
        possible_word = possible_word.strip()
        if len(possible_word) != len(word):
            continue
        if is_similiar_word(word, possible_word):
            result.append(possible_word)
    return result

def main():
    #najprv nacita vstup, skontroluje subor
    file = 'english_words.txt'
    file_obj = get_file_object(file)
    if not file:
        print('Problem with opening file!')
        return False

    vstup = input('Zadajte slovo: ')
    while vstup:
        print(vstup)
        print(find_similiar_words(vstup, file_obj))
        file_obj.seek(0)

        vstup = input('Zadajte slovo: ')


main()