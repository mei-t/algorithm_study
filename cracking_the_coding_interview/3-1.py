class ThreeStacks:
    def __init__(self, size):
        self.list = [None for _ in range(size)]
        self.size = size
        self.fir_i = 0
        self.sec_i = size * 2 / 3
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
        if self.thi_i <= self.size * 2 / 3:
            return False
        
        self.list[self.thi_i] = val
        self.thi_i -= 1
        return True
    
    def firstPop(self):
        if self.fir_i == 0:
            return None
        
        res = self.list[self.fir_i - 1]
        self.list[self.fir_i - 1] = None
        return res
    
    def secondPop(self):
        if self.sec_i == self.size * 2 / 3:
            return None
        
        res = self.list[self.sec_i + 1]
        self.list[self.sec_i + 1] = None
        return res
    
    def thirdPop(self):
        if self.thi_i == self.size:
            return None
        
        res = self.list[self.thi_i + 1]
        self.list[self.thi_i + 1] = None
        return res
