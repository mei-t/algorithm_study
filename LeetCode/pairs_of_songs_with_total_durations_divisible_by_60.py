from collections import defaultdict

class Solution:
    def numPairsDivisibleBy60(self, time):
        rest_duration = defaultdict(int)
        res = 0
        for t in time:
            res += rest_duration[t % 60]
            rest_duration[(60 - (t % 60)) % 60] += 1
        
        return res