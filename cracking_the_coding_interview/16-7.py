import sys
import unittest

def sign(a):
    return ((a >> (sys.getsizeof(a) - 1)) & 1) ^ 1

def get_max(a, b):
    k = sign(a - b)
    return a * k + b * (k ^ 1)

class Test(unittest.TestCase):
    def test_simple(self):
        self.assertEquals(get_max(16, 3), 16)
        self.assertEquals(get_max(16, -3), 16)
        self.assertEquals(get_max(-16, 3), 3)
        self.assertEquals(get_max(-16, -3), -3)
    
    def test_large_num(self):
        self.assertEquals(get_max(16000000, 3), 16000000)
        self.assertEquals(get_max(-16000000, 3), 3)

if __name__ == '__main__':
    unittest.main()