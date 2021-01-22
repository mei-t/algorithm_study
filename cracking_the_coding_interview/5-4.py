import unittest

def findNeightbors(num):
    pre_i = 1
    is_bottom_one = num & pre_i
    if is_bottom_one:
        while num & pre_i:
            pre_i <<= 1
    else:
        while not (num & pre_i):
            pre_i <<= 1
        pre_i >>= 1
    
    pre = num - pre_i if pre_i < num else None

    nex_i = 1
    is_one_appeared = False
    while not is_one_appeared or (num & nex_i):
        if num & nex_i:
            is_one_appeared = True
        nex_i <<= 1
    
    nex_i >>= 1
    nex = num + nex_i
    
    return pre, nex

class Test(unittest.TestCase):
    data = [
        (0b11010, 0b11001, 0b11100),
        (0b111, None, 0b1011),
        (0b100, 0b10, 0b1000),
        (0b10110, 0b10101, 0b11010),
        (0b1011, 0b111, 0b1101),
        (0b1101, 0b1011, 0b1110)
    ]
    def test_simple(self):
        for d in self.data:
            pre, nex = findNeightbors(d[0])
            self.assertEqual(pre, d[1])
            self.assertEqual(nex, d[2])

if __name__ == "__main__":
    unittest.main()