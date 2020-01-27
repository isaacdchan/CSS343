from collections import defaultdict
import sys

class Node:
    def __init__(self, count, val=None):
        self.left = None
        self.right = None
        self.count = count
        self.val = val

class Tree:
    def __init__(self, counts):
        self.counts = sorted(counts, key=lambda Node: Node.count)
        self.root = None
        self.build()

    def insert(self, node):
        i = 0
        while node.count < self.counts[i].count:
            i+=1
        
        self.counts.insert(i, node)

    def build(self):
        while len(self.counts) > 2:
            node1 = self.counts.pop(0)
            node2 = self.counts.pop(1)

            # if node1.val:
            #     print(node1.count, chr(node1.val))
            # if node2.val:
            #     print(node2.count, chr(node2.val))
            # print('-------')

            combinedNode = Node(node1.count + node2.count)
            self.insert(combinedNode)
        
        self.root = self.counts[0]

def encode(file_name):
    count_nodes = generate_counts(file_name)
    tree = Tree(count_nodes)
    generate_codes(tree.root)
    encoded_file_name = "encoded_" + file_name

def generate_counts(file_name):
    f = open(file_name, 'r')
    chars = f.read()

    ascii_dict = [0] * 256
    for char in chars:
        ascii_dict[ord(char)] += 1
    
    ascii_counts = []
    for ascii_code, count in enumerate(ascii_dict):
        if count > 0:
            ascii_counts.append(Node(count, ascii_code))

    return ascii_counts

def generate_codes(root):
    code_dict = defaultdict(str)

    def inorder(node, code):
        print(0)

        if node:
            print(1)
            if node.val:
                print(2)
                code_dict[node.val] = code

            inorder(root.left, code + "0")
            inorder(root.right, code + "1")

    inorder(root, "")

    for key, value in code_dict.items():
        print(key, value)


if __name__ == '__main__':
    if len(sys.argv) > 1:
        file_name_input = sys.argv[1]

        # try:
        f = open(file_name_input, 'r')
        encode(file_name_input)
        # except Exception as e:
        #     print('Error processing input:', e)

    else:
        print('Please re-run program with file name input')