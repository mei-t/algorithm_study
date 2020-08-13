import unittest

class ListNode:
    def __init__(self, val = -1):
        self.val = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.root = ListNode()
        self.cur = self.root

    def push_back(self, val):
        next = ListNode(val)
        self.cur.next = next
        self.cur = next

    def delete_first(self):
        node = self.root.next
        val = None
        if node:
            next = node.next
            self.root.next = next
            val = node.val
        del node
        return val

    def remove(self, val):
        prev = self.root
        node = prev.next
        while node and node.val != val:
            prev = node
            node = node.next
        if node:
            prev.next = node.next
        if node == self.cur:
            self.cur = prev
        del node

class LruCashe:
    def __init__(self):
        self.ll = LinkedList()
        self.max = 3
        self.dic = {}
    
    def insert(self, key, val):
        if key not in self.dic:
            if len(self.dic) >= self.max:
                item = self.ll.delete_first()
                del self.dic[item]
            self.dic[key] = val
        else:
            self.ll.remove(key)

        self.ll.push_back(key)


    def get(self, key):
        if key not in self.dic:
            return None
        self.ll.remove(key)
        self.ll.push_back(key)
        return self.dic[key]

class Test(unittest.TestCase):
    def test(self):
        lc = LruCashe()
        lc.insert(0, 6)
        self.assertEqual(lc.get(0), 6)
        lc.insert(1, 7)
        lc.insert(2, 8)
        lc.insert(3, 9)
        self.assertEqual(lc.get(0), None)
        self.assertEqual(lc.get(2), 8)

if __name__ == '__main__':
    unittest.main()