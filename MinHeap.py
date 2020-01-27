class MinHeap:

    def __init__(self):
        self.items = []

    @property
    def size(self):
        return len(self.items)

    def hasLeft(self, i):
        return self.getLeftIndex(i) < self.size
    def getLeftIndex(self, i):
        return (i * 2) + 1
    def getLeft(self, i):
        return self.items[self.getLeftIndex(i)]

    def hasRight(self, i):
        return self.getRightIndex(i) < self.size
    def getRightIndex(self, i):
        return (i * 2) + 2
    def getRight(self, i):
        return self.items[self.getRightIndex(i)]

    def hasParent(self, i):
        return i > 0
    def getParentIndex(self, i):
        return (i-1)//2
    def getParent(self, i):
        return self.items[self.getParentIndex(i)]

    def swap(self, i1, i2):
        self.items[i1], self.items[i2] = self.items[i2], self.items[i1]

    # removes min element (root) from the array
    def poll(self):
        if self.size > 0:
            # reserve the min element (first, top of queue)
            item = self.items[0]

            # swap last and first element
            self.swap(0, self.size-1)
            # remove the first element (now in last position)
            self.items.pop(self.size-1)
            # move the new first element to the correct location
            self.heapifyDown()
            return item

    def add(self, item):
        # add new item to end of items
        self.items.append(item)
        self.heapifyUp()
    
    def findSmallerChildIndex(self, i):
        smaller_child_index = self.getLeftIndex(i)
        if self.hasRight(i) and self.getRight(i) < self.getLeft(i):
            smaller_child_index = self.getRightIndex(i)

        return smaller_child_index
    
    def heapifyDown(self):
        i = 0

        while self.hasLeft(i): # if doesn't have left, definitely doesn't have right
            smaller_child_index = self.findSmallerChildIndex(i)
            
            if self.items[i] > self.items[smaller_child_index]:
                self.swap(i, smaller_child_index)
                index = smaller_child_index
            else:
                break
            
    def heapifyDown(self, i=0):
        if self.hasLeft(i):
            smaller_child_index = self.findSmallerChildIndex(i)

            if self.items[i] > self.items[smaller_child_index]:
                self.swap(i, smaller_child_index)
                self.heapifyDown(smaller_child_index)

    def heapifyUp(self):
        i = self.size - 1

        while self.hasParent(i) and self.getParent(i) > self.items[i]:
            self.swap(self.getParentIndex(i), i)
            i = self.getParentIndex(i)
    
    def heapifyUp(self, i=self.size - 1):
        # if current node is less than parent node
        if self.hasParent(i) and self.items[i] < self.getParent(i):
            # swap parent and child
            self.swap(self.getParentIndex(i), i)
            # check again
            heapifyUp(self.getParentIndex(i))

    def print(self):
        print(self.items)

Heap = MinHeap()
Heap.items = [10, 15, 20, 17]
Heap.print()
Heap.poll()
Heap.print()
Heap.add(8)
Heap.print()
Heap.add(10)
Heap.print()