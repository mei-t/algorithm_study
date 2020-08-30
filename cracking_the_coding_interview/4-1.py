import unittest

def is_root(start, end, graph):
    if start == end:
        return True

    q = graph[start]
    node_set = {start}
    while q:
        node = q.pop()
        if node == end:
            return True
        if node in node_set:
            continue
        q += graph[node]
        node_set.add(node)
    return False

class Test(unittest.TestCase):
    graph = { 0: [1, 2],
              1: [2, 3],
              2: [5],
              3: [4],
              4: [],
              5: [6],
              6: [2]}
    
    def test_true_simple(self):
        self.assertTrue(is_root(1, 3, self.graph))
        
    def test_false_simple(self):
        self.assertFalse(is_root(4, 2, self.graph))

    def test_true_long(self):
        self.assertTrue(is_root(0, 4, self.graph))

    def test_false_loop(self):
        self.assertFalse(is_root(2, 3, self.graph))

    def test_true_same(self):
        self.assertTrue(is_root(3, 3, self.graph))

if __name__ == '__main__':
    unittest.main()