import unittest

class SetOfStacks:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cur_s = []
        self.stack_s = [0]
        self.stack_d = {0: self.cur_s}
    
    def push(self, val):
        if len(self.cur_s) < self.capacity:
            self.cur_s.append(val)
            return

        self.cur_s = [val]
        i = self.stack_s[-1]
        self.stack_s.append(i + 1)
        self.stack_d[i + 1] = self.cur_s

    def pop(self):
        res = self.cur_s.pop()
        if len(self.cur_s) == 0:
            del self.stack_d[self.stack_s.pop()]
        return res
    
    def popAt(self, i):
        stack_num = i // self.capacity
        index = i % self.capacity
        res = self.stack_d[stack_num].pop(index)
        for j in range(stack_num + 1, self.stack_s[-1] + 1):
            tmp = self.stack_d[j].pop(0)
            self.stack_d[j - 1].append(tmp)
        return res

class Test(unittest.TestCase):
    def test_simple(self):
        sos = SetOfStacks(3)
        for i in range(10):
            sos.push(i)
        
        self.assertEqual(sos.pop(), 9)
        self.assertEqual(sos.popAt(2), 2)
        self.assertEqual(sos.popAt(5), 6)

if __name__ == '__main__':
    unittest.main()