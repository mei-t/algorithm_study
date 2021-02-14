from enum import Enum

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
        print(type(e))
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
    if not a:
        return []
    start, end = 0, 0
    snc = StrNumCount(a[0])
    snc.increment()
    max_len = 0
    max_range = [0, 0]
    while True:
        while end < len(a) - 1 and sn_type(a[end + 1]) is snc.type:
            end += 1
            snc.increment()
        print(end)
        snc.type = opposite(snc.type)
        while end < len(a) - 1 and snc.count() < snc.opp_count()\
            and sn_type(a[end + 1]) == snc.type:
            end += 1
            snc.increment()
        print(end)
        print(snc.count(), snc.opp_count())
        while start < end and snc.count() < snc.opp_count():
            # import pdb; pdb.set_trace()
            print("a[start] = ", a[start])
            snc.decrement(a[start])
            start += 1
        print(start)

        if max_len < end - start + 1:
            max_len = end - start + 1
            max_range = [start, end + 1]
        
        if end + 1 >= len(a):
            break
        snc.type = sn_type(a[end + 1])
    
    return a[max_range[0]: max_range[1]]

if __name__ == '__main__':
    a = [0, 0, "a", 3, 1, 5, 7, 23, "o", "w", "n", 0, "t", 9, 71, "r", 39, 0, 5, 7]
    res = find_eq_subarray(a)
    print(res)