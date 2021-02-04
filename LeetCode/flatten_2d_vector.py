# 27:47 問題勘違いしてた

class Vector2D(object):

    def __init__(self, v):
        self.v = v
        self.inner = 0
        self.outer = 0
    
    def move_next(self):
        while self.outer < len(self.v) and self.inner == len(self.v[self.outer]):
            self.outer += 1
            self.inner = 0

    def next(self):
        self.move_next()
        res = self.v[self.outer][self.inner]
        self.inner += 1
        return res
        

    def hasNext(self):
        self.move_next()
        return self.outer < len(self.v)

# 勘違いしてた
class Vector2D1(object):

    def __init__(self, v):
        def flatten(nums):
            if nums == None:
                return
            if type(nums) is not list:
                self.res.append(nums)
                return
            for num in nums:
                flatten(num)
                
        self.res = []
        flatten(v)
        self.pos = 0

    def next(self):
        num = self.res[self.pos]
        self.pos += 1
        return num
        

    def hasNext(self):
        return self.pos < len(self.res)

if __name__ == '__main__':
    v = [[1,2],[3],[4]]
    obj = Vector2D(v)
    print(obj.next())
    print(obj.next())
    print(obj.hasNext())
    print(obj.next())
    print(obj.next())
    print(obj.hasNext())