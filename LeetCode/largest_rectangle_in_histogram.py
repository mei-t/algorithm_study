import heapq

class Solution:
    def largestRectangleArea(self, heights):
        q = []
        for i, height in enumerate(heights):
            heapq.heappush(q, [-height, i])
        
        res = 0
        start_map = dict()
        end_map = dict()
        while q:
            h = heapq.heappop(q)
            if h[1] - 1 in end_map and h[1] + 1 in start_map:
                pos = end_map[h[1] - 1]
                pos[1] = start_map[h[1] + 1][1]
                end_map[pos[1]] = pos
                del end_map[h[1] - 1]
                del start_map[h[1] + 1]
            elif h[1] - 1 in end_map:
                pos = end_map[h[1] - 1]
                del end_map[h[1] - 1]
                pos[1] = h[1]
                end_map[h[1]] = pos
            elif h[1] + 1 in start_map:
                pos = start_map[h[1] + 1]
                del start_map[h[1] + 1]
                pos[0] = h[1]
                start_map[h[1]] = pos
            else:
                pos = [h[1], h[1]]
                start_map[h[1]] = pos
                end_map[h[1]] = pos
            
            res = max(res, -h[0] * (pos[1] - pos[0] + 1))
        
        return res