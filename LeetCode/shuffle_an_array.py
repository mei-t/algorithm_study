class Solution:

    def __init__(self, nums):
        self.nums = nums
        

    # Resets the array to its original configuration and return it.
    def reset(self):
        return self.nums


    # Returns a random shuffling of the array.
    def shuffle(self):
        res = list(self.nums)
        for i in range(len(res)):
            index = random.randint(0, i)
            res[index], res[i] = res[i], res[index]
        return res
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()