#jednoduchy strom
class Tree:
    """Toto reprezentuje strom. Lubovolny strom
    je mozne vytvorit pripojenim naslednikov
    (uzlov s podstromami) k root"""

    def __init__(self, root):
        "Skontrsuuj strom s jednym uzlom"
        self.root = root
    
    def add(self, subtree):
        "pripoji podstrom ku korenu"
        self.root.children.append(subtree)

    def __repr__(self):
        return 'Strom = {0}'.format(self.root)

class Node:
    "Node nesie data uzlu s drzi zoznam naslednikov"

    def __init__(self, value, children=None):
        self.value = value
        self.children = children if children is not None else []

    def __repr__(self):
        return 'Uzol({0}, {1})'.format(self.value, self.children)

"""
            Najvyssi tucniak
        /                   \
    Karlikov otec          strycek tucek
    /    |       \              \
karolin  adalbert karlik        los karlos
"""
left_subtree = Tree(Node('Karlikov otec'))
left_subtree.add(Node('Karolin'))
left_subtree.add(Node('Adalbert'))
left_subtree.add(Node('Karlik'))

right_subtree = Tree(Node('Strycek Tucek'))
right_subtree.add(Node('Los Karlos'))

tree = Tree(Node('Najvyssi tucniak'))
tree.add(left_subtree)
tree.add(right_subtree)

print(tree)
