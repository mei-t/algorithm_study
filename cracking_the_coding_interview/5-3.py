import unittest

# 0は含まないと仮定
def inversionPos(num):
    bit_list = [0]
    i = 0
    is_one = True
    while num:
        if (num & 1) ^ is_one:
            bit_list.append(1)
            i += 1
            is_one = not is_one
        else:
            bit_list[i] += 1
        num >>= 1

    if len(bit_list) == 1:
        return bit_list[0]
    
    max_l = 0
    for i in range(len(bit_list) - 2):
        next_one = bit_list[i + 2] if bit_list[i + 1] == 1 else 0
        l = bit_list[i] + next_one + 1
        max_l = max(max_l, l)
        
    max_l = max(max_l, bit_list[-1] + 1)
    
    return max_l

class Test(unittest.TestCase):
    def test_simple(self):
        self.assertEqual(inversionPos(0b11011101111), 8)
        self.assertEqual(inversionPos(0b1101100111), 5)
        self.assertEqual(inversionPos(0b1001100111), 4)
    
    def test_edge_case(self):
        self.assertEqual(inversionPos(1), 1)
        self.assertEqual(inversionPos(2), 2)
        self.assertEqual(inversionPos(3), 2)
        self.assertEqual(inversionPos(4), 2)
        self.assertEqual(inversionPos(5), 3)

if __name__ == '__main__':
    unittest.main()