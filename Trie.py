def get_position(letter):
    return ord(letter) - ord('a')

class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isEndofWord = False

    def isEmpty(self):
        return all(letter is None for letter in self.children)

    def insert(self, word):
        if not word:
            self.isEndofWord = True
            return

        index = get_position(word[0])

        if not self.children[index]:
            self.children[index] = TrieNode()

        self.children[index].insert(word[1:])

    def search(self, word):
        if not word:
            return True
        
        index = get_position(word[0])

        if not self.children[index]:
            return False
        else:
            return self.children[index].search(word[1:])

    def remove(self, word):
        if not word:
            return False

        index = get_position(word[0])

        if not self.children[index]:
            return False

        if len(word) == 1:
            last_node = self.children[index]
            if last_node.isEmpty():
                self.children.pop(index)
            else:
                last_letter.isEndofWord = False

            return True

        return self.children[index].remove(word[1:])

if __name__ == "__main__":
    root = TrieNode()
    root.insert("dog")
    root.insert("deoo")
    root.insert("dog")
    root.insert("deog")