import unittest

class ListNode:
    def __init__(self, key = None, val = None):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LinkedList:
    def __init__(self):
        self.root = ListNode()
        self.cur = self.root

    def push_back(self, node):
        self.cur.next = node
        node.prev = self.cur
        self.cur = node

    def delete_first(self):
        node = self.root.next
        key = None
        if node:
            next = node.next
            self.root.next = next
            next.prev = self.root
            key = node.key
        return key

    def remove_node(self, node):
        prev = node.prev
        next = node.next
        if next:
            prev.next = next
            next.prev = prev
        else:
            prev.next = None
            self.cur = prev
        return node

class LruCache:
    def __init__(self):
        self.ll = LinkedList()
        self.max = 3
        self.dic = {}
    
    def insert(self, key, val):
        node = None
        if key not in self.dic:
            node = ListNode(key, val)
            if len(self.dic) >= self.max:
                delete_key = self.ll.delete_first()
                del_node = self.dic[delete_key]
                del self.dic[delete_key]
                del del_node
            self.dic[key] = node
        else:
            node = self.ll.remove_node(self.dic[key])

        self.ll.push_back(node)

    def get(self, key):
        if key not in self.dic:
            return None
        self.ll.remove_node(self.dic[key])
        self.ll.push_back(self.dic[key])
        return self.dic[key].val


class Test(unittest.TestCase):
    def test1(self):
        lc = LruCache()
        lc.insert(0, 6)
        self.assertEqual(lc.get(0), 6)
        lc.insert(1, 7)
        lc.insert(2, 8)
        lc.insert(3, 9)
        self.assertEqual(lc.get(0), None)
        self.assertEqual(lc.get(2), 8)
    
    def test2(self):
        lc = LruCache()
        lc.insert(0, 6)
        lc.insert(1, 7)
        lc.insert(2, 8)
        self.assertEqual(lc.get(0), 6)
        lc.insert(3, 9)
        self.assertEqual(lc.get(0), 6)
        self.assertEqual(lc.get(1), None)
        self.assertEqual(lc.get(2), 8)

if __name__ == '__main__':
    unittest.main()