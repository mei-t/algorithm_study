import unittest

class MyQueue(object):
    def __init__(self):
        self.s1 = []
        self.s2 = []

    def put(self, val):
        while len(self.s2) > 0:
            self.s1.append(self.s2.pop())
        self.s1.append(val)
        return
    
    def get(self):
        if not self.s1 and not self.s2:
            return None
        while len(self.s1) > 1:
            self.s2.append(self.s1.pop())
        return self.s1.pop() if self.s1 else self.s2.pop()

class Test(unittest.TestCase):
    def test_simple(self):
        q = MyQueue()
        q.put(0)
        q.put(1)
        q.put(2)
        self.assertEqual(q.get(), 0)
        q.put(3)
        self.assertEqual(q.get(), 1)
        self.assertEqual(q.get(), 2)
        self.assertEqual(q.get(), 3)
        self.assertEqual(q.get(), None)
        q.put(4)
        self.assertEqual(q.get(), 4)

if __name__ == "__main__":
    unittest.main()