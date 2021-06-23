import heapq

class Solution:
    def connectSticks(self, sticks):
        heapq.heapify(sticks)
        
        cost = 0
        while len(sticks) > 1:
            x = heapq.heappop(sticks)
            y = heapq.heappop(sticks)
            cost += x + y
            heapq.heappush(sticks, x + y)
        
        return cost