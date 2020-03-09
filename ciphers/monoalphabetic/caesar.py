class Caesar:
    def __init__(self, alphabet=None):
        self.alphabet = [chr(i + 97) for i in range(26)] if alphabet is None else alphabet.lower()
        self.alpha_len = len(self.alphabet)

    def encode(self, input_text, offset):
        sign = -1 if offset < 0 else 1
        offset = abs(offset) % self.alpha_len * sign

        encoded_text = ""
        input_text = input_text.lower().rstrip().lstrip()

        for letter in input_text:
            try:   
                index = self.alphabet.index(letter)
            except ValueError:
                encoded_text += letter
                continue

            new_index = index + offset
            if new_index >= self.alpha_len:
                new_index -= self.alpha_len
            elif new_index < 0:
                new_index = self.alpha_len - index - 1

            encoded_text += self.alphabet[new_index]

        return encoded_text

    def decode(self, input_text, offset):
        sign = -1 if offset < 0 else 1
        offset = abs(offset) % self.alpha_len * sign

        decoded_text = ""
        input_text = input_text.lower().lstrip().rstrip()

        for letter in input_text:
            try:
                index = self.alphabet.index(letter)
            except ValueError:
                decoded_text += letter
                continue

            new_index = index - offset
            if new_index < 0:
                new_index = self.alpha_len - index - 1
            elif new_index >= self.alpha_len:
                new_index -= self.alpha_len

            decoded_text += self.alphabet[new_index]

        return decoded_text

cipher = Caesar(" .,?!ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
sprava = cipher.encode("ahoj", 18)
normal = cipher.decode("P6PYG9Z5IGM25453J", 11)
print(sprava)
print(normal)