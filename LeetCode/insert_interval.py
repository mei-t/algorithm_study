# 58:56
class Solution(object):
    def insert(self, intervals, newInterval):
        if not intervals:
            return [newInterval]
        intervals.insert(0, [0, 0])
        intervals.append([float('inf'), float('inf')])
        i = 0
        res = []
        while intervals[i][1] < newInterval[0]:
            if i != 0:
                res.append(intervals[i])
            i += 1
        
        j = i
        while intervals[j][0] <= newInterval[1]:
            j += 1
            
        res.append([min(intervals[i][0], newInterval[0]), max(intervals[j-1][1], newInterval[1])])
        for k in range(j, len(intervals) - 1):
            res.append(intervals[k])
        return res