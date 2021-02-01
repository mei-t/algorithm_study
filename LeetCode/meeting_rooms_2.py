import heapq

class Solution(object):
    def minMeetingRooms(self, intervals):
        intervals.sort()
        q = []
        count = 0
        for interval in intervals:
            while q and q[0] <= interval[0]:
                heapq.heappop(q)
            heapq.heappush(q, interval[1])
            if len(q) > count:
                count = len(q)
        
        return count

if __name__ == '__main__':
    intervals = [[0, 30], [5, 10], [15, 20]]
    sol = Solution()
    res = sol.minMeetingRooms(intervals)
    print(res)