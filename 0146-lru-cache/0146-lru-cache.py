class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.left = self.right = None

class LRUCache:
    
    def __init__(self, capacity):
        self.capacity = capacity
        self.nodeMapping = {}
        
        self.mostLeft, self.mostRight = Node(0,0), Node(0,0)
        self.mostLeft.right, self.mostRight.left = self.mostRight, self.mostLeft
    
    def remove(self, node):
        node.left.right = node.right
        node.right.left = node.left
    
    def insert(self, node):
        node.left = self.mostRight.left
        node.right = self.mostRight
        self.mostRight.left.right = node
        self.mostRight.left = node

    def get(self, key):
        if key in self.nodeMapping:
            node = self.nodeMapping[key]
            self.remove(node)
            self.insert(node)
            return node.val
        return -1

    def put(self, key, value):
        if key in self.nodeMapping:
            self.remove(self.nodeMapping[key])
        self.nodeMapping[key] = Node(key, value)
        self.insert(self.nodeMapping[key])
        
        if len(self.nodeMapping) > self.capacity:
            nodeToRemove = self.mostLeft.right
            self.remove(nodeToRemove)
            del self.nodeMapping[nodeToRemove.key]
        
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)