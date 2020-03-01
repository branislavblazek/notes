class Atbash():
    def __init__(self, alphabet=None):
        self.alphabet = [chr(i+97) for i in range(26)] if alphabet is None else alphabet.lower()

    def encode(self, text):
        input_text = text.lower()

        decoded_text = ""

        for letter in input_text:
            try:
                letter_index = self.alphabet.index(letter)
            except ValueError:
                decoded_text += letter
                continue

            new_index = len(self.alphabet) - letter_index
            decoded_text += self.alphabet[new_index - 1]
        
        return decoded_text

    def decode(self, text):
        input_text = text.lower()

        decoded_text = ""

        for letter in input_text:
            try:
                letter_index = self.alphabet.index(letter)
            except ValueError:
                decoded_text += letter
                continue

            new_index = len(self.alphabet) - letter_index
            decoded_text += self.alphabet[new_index - 1]

        return decoded_text


cipher = Atbash("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
sprava = cipher.encode('We are discovered!')
print(sprava)
normal = cipher.decode('zrkp gouf')
print(normal)