from enum import Enum
import unittest

class StrNumType(Enum):
    STRING = 0
    NUMBER = 1

class StrNumCount:
    def __init__(self, e):
        self.type = sn_type(e)
        self.str_count = 0
        self.num_count = 0
    
    def increment(self):
        if self.type is StrNumType.NUMBER:
            self.num_count += 1
        else:
            self.str_count += 1
    
    def decrement(self, e):
        if type(e) is int:
            self.num_count -= 1
        else:
            self.str_count -= 1
    
    def count(self):
        return self.num_count if self.type is StrNumType.NUMBER else self.str_count
    
    def opp_count(self):
        return self.str_count if self.type is StrNumType.NUMBER else self.num_count
    
    # def opposite():
    #     if self.type

def sn_type(e):
    if type(e) is int:
        return StrNumType.NUMBER
    return StrNumType.STRING

def opposite(t):
    if t == StrNumType.STRING:
        return StrNumType.NUMBER
    return StrNumType.STRING

def find_eq_subarray(a):
    if len(a) < 2:
        return []
    start, end = 0, 0
    snc = StrNumCount(a[0])
    max_len = 0
    max_range = [0, 0]
    while True:
        while end < len(a) and sn_type(a[end]) is snc.type:
            end += 1
            snc.increment()
        snc.type = opposite(snc.type)
        while end < len(a) and snc.count() < snc.opp_count()\
            and sn_type(a[end]) == snc.type:
            end += 1
            snc.increment()
        while start < end and snc.count() < snc.opp_count():
            snc.decrement(a[start])
            start += 1

        if max_len < end - start:
            max_len = end - start
            max_range = [start, end]
        
        if end + 1 >= len(a):
            break
        snc.type = sn_type(a[end])
    
    return a[max_range[0]: max_range[1]]

class Test(unittest.TestCase):
    data = [
        [
            [0, 0, "a", 3, 1, 5, 7, 23, "o", "w", "n", 0, "t", 9, 71, "r", 39, 0, 5, 7],
            [7, 23, 'o', 'w', 'n', 0, 't', 9, 71, 'r'] # 他にも正解あり
        ],
        [["s"], []],
        [[0, "s"], [0, "s"]]
    ]

    def test_simple(self):
        for d in self.data:
            self.assertEqual(find_eq_subarray(d[0]), d[1])

if __name__ == '__main__':
    unittest.main()