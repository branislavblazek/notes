class Trie:
    def __init__(self, node=None):
        self.root = TrieNode() if node is None else node
    
    def insert(self, word, value):
        node = self.root

        for letter in word:
            index = index_from_letter(letter)
            if node.children[index] is not None:
                node = node.children[index]
            else:
                new_node = TrieNode()
                node.children[index] = new_node
                node = new_node
        node.value = value
        node.accepting = True

    def search(self, word):
        node = self.root

        for letter in word:
            index = index_from_letter(letter)
            if node.children[index] is not None:
                node = node.children[index]
            else:
                return None
        if node.accepting:
            return node.value

class TrieNode:
    def __init__(self, value=None):
        self.value = value
        self.children = [None for _ in range(26)]
        self.accepting = False

def index_from_letter(letter):
    return ord(letter) - ord('a')

trie = Trie()
trie.insert("ahoj", "Hello")
trie.insert("ab", "ab")
print(trie.search("ahoj"))
>>Hello