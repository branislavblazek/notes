class BinaryTree:
    def __init__(self, root):
        self.root = root

    def __repr__(self):
        self.__show(self.root)
        return ' '

    def __show(self, node):
        if not node:
            return 'there is nothing'

        self.__show(node.left)
        print(node.value)
        self.__show(node.right)

    def find(self, node, value):
        if not node:
            return
        
        if node.value == value:
            return node
        elif value < node.value:
            return self.find(node.left, value)
        elif value > node.value:
            return self.find(node.right, value)

    def min(self, node):
        if not node.left:
            return node
        else:
            return self.min(node.left)

    def insert(self, node, value, is_end=False):
        if node is None:
            new_node = Node(value)
            Tree.root = new_node
            return

        if is_end:
            new_node = Node(value)

            if value < node.value:
                node.left = new_node
            else:
                node.right = new_node
            new_node.parent = node

            return

        if value < node.value:
            if node.left == None:
                self.insert(node, value, True)
            else:
                self.insert(node.left, value)
        elif value > node.value:
            if node.right == None:
                self.insert(node, value, True)
            else:
                self.insert(node.right, value)
        elif value == node.value:
            return None

    def minValueNode(self, node):
        current = node
        while node.left is not None:
            current = current.left

        return current

    def delete(self, node, value):
        if not node:
            return None
        
        if value < node.value:
            node.left = self.delete(node.left, value)
        elif value > node.value:
            node.right = self.delete(node.right, value)
        else:
            if node.left == None:
                temp = node.right
                node = None
                return temp
            elif node.right == None:
                temp = node.left
                node = None
                return temp
            
            temp = self.minValueNode(node.right)
            node.value = temp.value
            node.right = self.delete(node.right, temp.value)

        return node
    

class Node:
    def __init__(self, value):
        self.value = value
        self.parent = None
        self.left = None
        self.right = None


# -----Moj test------
#Strom:
#        5
#      /  \
#     2    8
#   /  \  /  \
#  1   3  6  10
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

Tree = BinaryTree(node7)
Tree.delete(Tree.root, 2)
print(Tree)