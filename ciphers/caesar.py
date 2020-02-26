class Caesar:
    def __init__(self):
        self.alpha_offset = 97
        self.alphabet = [chr(i + self.alpha_offset) for i in range(26)]

    def decode(self, input_text, offset):
        offset = offset % 26

        decoded_text = ""
        input_text = input_text.lower().rstrip().lstrip()

        for letter in input_text:
            try:   
                index = self.alphabet.index(letter)
            except ValueError:
                decoded_text += letter
                continue

            new_index = index + offset
            if new_index >= len(self.alphabet):
                new_index -= len(self.alphabet)

            decoded_text += chr(new_index + self.alpha_offset)

        return decoded_text

    def encode(self, input_text, offset):
        offset = offset % 26

        encoded_text = ""
        input_text = input_text.lower().lstrip().rstrip()

        for letter in input_text:
            try:
                index = self.alphabet.index(letter)
            except ValueError:
                encoded_text += letter
                continue

            new_index = index - offset
            if new_index < 0:
                new_index = len(self.alphabet) - index - 1

            encoded_text += chr(new_index + self.alpha_offset)

        return encoded_text

cipher = Caesar()
sprava = cipher.decode('Zacnite s vystahovanim!', 1)
normal = cipher.encode(sprava, 1)
print(normal)