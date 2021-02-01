import heapq

class Solution1(object):
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

class Solution2(object):
    def minMeetingRooms(self, intervals):
        intervals.sort()
        q = []
        for interval in intervals:
            while q and q[0] != 0 and q[0] <= interval[0]:
                heapq.heappop(q)
                heapq.heappush(q, 0)
            if q and q[0] == 0:
                heapq.heappop(q)
            heapq.heappush(q, interval[1])
        
        return len(q)

class Solution(object):
    def minMeetingRooms(self, intervals):
        intervals.sort()
        q = []
        heapq.heappush(q, intervals[0][1])
        for interval in intervals[1:]:
            if q[0] <= interval[0]:
                heapq.heappop(q)
            heapq.heappush(q, interval[1])
        
        return len(q)

if __name__ == '__main__':
    intervals = [[0, 30], [5, 10], [15, 20]]
    sol = Solution()
    res = sol.minMeetingRooms(intervals)
    print(res)