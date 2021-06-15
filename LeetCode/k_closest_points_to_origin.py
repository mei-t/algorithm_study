import heapq
import math

class Solution:
    def kClosest(self, points, k):
        if len(points) == k:
            return points
        
        h = []
        max_dist = 0
        for point in points:
            dist = math.sqrt(point[0] ** 2 + point[1] ** 2)
            if len(h) >= k and dist > max_dist:
                continue
            heapq.heappush(h, [dist, point])
            max_dist = max(max_dist, dist)
        
        res = []
        for _ in range(k):
            tmp = heapq.heappop(h)
            res.append(tmp[1])
        
        return res
        