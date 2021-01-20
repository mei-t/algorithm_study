import unittest

class MyQueue(object):
    def __init__(self):
        self.newest = []
        self.oldest = []

    def put(self, val):
        while len(self.oldest) > 0:
            self.newest.append(self.oldest.pop())
        self.newest.append(val)
        return
    
    def get(self):
        while len(self.newest) > 0:
            self.oldest.append(self.newest.pop())
        return self.oldest.pop() if self.oldest else None

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