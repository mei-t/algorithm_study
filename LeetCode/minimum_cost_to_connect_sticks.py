import heapq

class Solution:
    def connectSticks(self, sticks):
        h = []
        for stick in sticks:
            heapq.heappush(h, stick)
        
        cost = 0
        while len(h) > 1:
            x = heapq.heappop(h)
            y = heapq.heappop(h)
            cost += x + y
            heapq.heappush(h, x + y)
        
        return cost