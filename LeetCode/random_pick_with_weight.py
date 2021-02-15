import random

class Solution(object):

    def __init__(self, w):
        self.sum = 0
        self.w = w
        for i, num in enumerate(w):
            self.sum += num
            self.w[i] = self.sum

    def pickIndex(self):
        r = random.randrange(self.sum)
        for i in range(len(self.w)):
            if r <= self.w[i]:
                break
        
        return i