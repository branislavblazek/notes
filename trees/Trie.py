class Trie:
    def __init__(self, node=None):
        self.root = TrieNode() if node is None else node

class TrieNode:
    def __init__(self, value=None):
        self.value = value
        self.children = [None for _ in range(26)]
        self.accepting = False

def index_from_letter(letter):
    return ord(letter) - ord('a')

def insert(trie, word, value):
    node = trie.root

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

def search(trie, word):
    node = trie.root

    for letter in word:
        index = index_from_letter(letter)
        if node.children[index] is not None:
            node = node.children[index]
        elif node.children[index] is None:
            return None
    if node.accepting:
        return node.value

trie = Trie()
insert(trie, "ahoj", "Hello")
insert(trie, "ab", "ab")
print(search(trie, "aho"))