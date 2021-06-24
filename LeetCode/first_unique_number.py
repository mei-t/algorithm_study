from collections import defaultdict, deque

class FirstUnique:


    def __init__(self, nums):
        self.nums = nums
        self.num_map = defaultdict(int)
        self.idx = 0
        for num in nums:
            self.num_map[num] += 1
        

    def showFirstUnique(self):
        if self.idx == len(self.nums):
            return -1
        while self.num_map[self.nums[self.idx]] > 1:
            self.idx += 1
            if self.idx == len(self.nums):
                return -1
        return self.nums[self.idx]
        

    def add(self, value):
        self.nums.append(value)
        self.num_map[value] += 1
        


# Your FirstUnique object will be instantiated and called as such:
# obj = FirstUnique(nums)
# param_1 = obj.showFirstUnique()
# obj.add(value)


class FirstUnique2:


    def __init__(self, nums):
        self.nums = deque(nums)
        self.num_map = defaultdict(int)
        for num in nums:
            self.num_map[num] += 1
        

    def showFirstUnique(self):
        if not self.nums:
            return -1
        
        num = self.nums.popleft()
        while self.num_map[num] > 1:
            if not self.nums:
                return -1
            num = self.nums.popleft()
            
        self.nums.appendleft(num)
        return num
        

    def add(self, value):
        self.nums.append(value)
        self.num_map[value] += 1
        