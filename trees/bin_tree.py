class BinaryTree:
    def __init__(self, root):
        self.root = root
    
    def __repr__(self):
        self.print_tree()
        return ' '

    def __from_min(self, node):
        if not node:
            return 'there is nothing'

        self.__from_min(node.left)
        print(node.value)
        self.__from_min(node.right)

    def from_min(self):
        self.__from_min(self.root)

    def print_tree(self):
        print('Strom = ({0})'.format(self.root))

    #Vyhladavanie
    def search(self, value):
        node = self.root
        while node is not None and node.value != value:
            if value < node.value:
                node = node.left
            elif value > node.value:
                node = node.right
            elif value == node.value:
                return node
        if node is not None and node.value == value:
            return node
        return None

    #Pridanie
    def insert(self, value):
        node = self.root
        parent = None

        while node is not None:
            parent = node
            if node.value <= value:
                node = node.right
            else:
                node = node.left

        node = Node(value)
        node.parent = parent
        
        if parent is None:
            self.root = node
        else:
            if parent.value <= value:
                parent.right = node
            else:
                parent.left = node

    #Mazanie
    def delete(self, value):
        node = self.root
        while node is not None and node.value != value:
            if node.value > value:
                node = node.left
            else:
                node = node.right
        #pokial to nie je v strome, kasli na to
        if node is None:
            return

        #prvy pripad
        #je to list
        if node.left == None and node.right == None:
            if node.parent is None:
                self.root = None
            elif node.parent.left == node:
                node.parent.left = None
            elif node.parent.right == node:
                node.parent.right = None

        #druhy pripad
        #ma jednoho potomka
        elif node.left == None:
            if node.parent is None:
                self.root = node.right
            elif node.parent.left == node:
                node.parent.left = node.right
            elif node.parent.right == node:
                node.parent.right = node.right

        elif node.right == None:
            if node.parent is None:
                self.root = node.left
            elif node.parent.left == node:
                node.parent.left = node.left
            elif node.parent.right == node:
                node.parent.right = node.left

        #treti pripad
        else:
            def najlavejsi(node_x):
                node_x = node_x.right
                while node_x.left is not None:
                    node_x = node_x.left
                return node_x

            pridaj = najlavejsi(node).value
            self.delete(None)
            node.value = pridaj

class Node:
    def __init__(self, value):
        self.value = value
        self.parent = None
        self.left = None
        self.right = None

    def __repr__(self):
        return 'Uzol: {}, deti: {}, {};'.format(str(self.value), self.left, self.right)

# -----Moj test------
#Strom:
#        5
#      /  \
#     2    8
#   /  \  /  \
#  1   3  6  10
"""
node1 = Node(1)
node2 = Node(3)
node3 = Node(6)
node4 = Node(10)
node5 = Node(2)
node6 = Node(8)
node7 = Node(5)

node1.parent = node5
node2.parent = node5
node5.left = node1
node5.right = node2

node3.parent = node6
node4.parent = node6
node6.left = node3
node6.right = node4

node5.parent = node7
node6.parent = node7
node7.left = node5
node7.right = node6

Tx = BinaryTree(node7)
Tx.delete(2)
print(Tx)
"""
node1 = Node(8)
node2 = Node(9)
node3 = Node(10)

node1.parent = node2

node2.left = node1
node2.parent = node3

node3.left = node2

Tree = BinaryTree(node3)
print(Tree)
Tree.delete(10)
print(Tree)