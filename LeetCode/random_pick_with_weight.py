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
        left = 0
        right = len(self.w)
        while left < right:
            mid = (left + right) // 2
            if r < self.w[mid] and (mid == 0 or self.w[mid - 1] < r):
                return mid
            elif r >= self.w[mid]:
                left = mid + 1
            else:
                right = mid
        return left

class Solution1(object):

    def __init__(self, w):
        self.sum = 0
        self.w = w
        for i, num in enumerate(w):
            self.sum += num
            self.w[i] = self.sum

    def pickIndex(self):
        r = random.randrange(self.sum)
        for i in range(len(self.w)):
            if r < self.w[i]:
                break
        
        return i
        