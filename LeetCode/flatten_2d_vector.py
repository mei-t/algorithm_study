class Vector2D(object):

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
    v = [[[[1,2],[3],[4]]],[None],[None],[None],[None],[None],[None],[None]]
    obj = Vector2D(v)
    print(obj.next())
    print(obj.next())
    print(obj.hasNext())
    print(obj.next())
    print(obj.next())
    print(obj.hasNext())