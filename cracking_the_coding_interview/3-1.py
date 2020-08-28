import unittest

class ThreeStacks:
    def __init__(self, size):
        self.list = [None for _ in range(size)]
        self.size = size
        self.fir_i = 0
        self.sec_i = (size * 2 - 1) // 3
        self.thi_i = size - 1
    
    def pushFirst(self, val):
        if self.fir_i > self.sec_i:
            return False
        
        self.list[self.fir_i] = val
        self.fir_i += 1
        return True
    
    def pushSecond(self, val):
        if self.fir_i > self.sec_i:
            return False
        
        self.list[self.sec_i] = val
        self.sec_i -= 1
        return True
    
    def pushThird(self, val):
        if self.thi_i <= (self.size * 2 - 1) // 3:
            return False
        
        self.list[self.thi_i] = val
        self.thi_i -= 1
        return True
    
    def popFirst(self):
        if self.fir_i == 0:
            return None
        
        res = self.list[self.fir_i - 1]
        self.list[self.fir_i - 1] = None
        self.fir_i -= 1
        return res
    
    def popSecond(self):
        if self.sec_i == (self.size * 2 - 1) // 3:
            return None
        
        res = self.list[self.sec_i + 1]
        self.list[self.sec_i + 1] = None
        self.sec_i += 1
        return res
    
    def popThird(self):
        if self.thi_i == self.size - 1:
            return None
        
        res = self.list[self.thi_i + 1]
        self.list[self.thi_i + 1] = None
        self.thi_i += 1
        return res


class Test(unittest.TestCase):
    def test_first_second_simple(self):
        ts = ThreeStacks(6)
        self.assertTrue(ts.pushFirst(0))
        self.assertTrue(ts.pushFirst(1))
        self.assertTrue(ts.pushSecond(0))
        self.assertTrue(ts.pushSecond(1))
        self.assertFalse(ts.pushFirst(2))
        self.assertTrue(ts.pushThird(0))
        self.assertTrue(ts.pushThird(1))
        self.assertFalse(ts.pushThird(2))
        
        self.assertEqual(ts.popFirst(), 1)
        self.assertEqual(ts.popFirst(), 0)
        self.assertEqual(ts.popFirst(), None)
        self.assertEqual(ts.popSecond(), 1)
        self.assertEqual(ts.popSecond(), 0)
        self.assertEqual(ts.popSecond(), None)
        self.assertEqual(ts.popThird(), 1)
        self.assertEqual(ts.popThird(), 0)
        self.assertEqual(ts.popThird(), None)

if __name__ == '__main__':
    unittest.main()