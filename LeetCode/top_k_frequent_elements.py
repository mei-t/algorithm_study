import heapq
class Solution(object):
    def topKFrequent(self, nums, k):
        num_map = self.createMap(nums)
        q = self.findKFrequent(num_map, k)

        res = []
        while q:
            e = heapq.heappop(q)
            res.append(e[1])
        return res
    
    def createMap(self, nums):
        num_map = dict()
        for num in nums:
            if num not in num_map:
                num_map[num] = 0
            num_map[num] += 1
        return num_map

    def findKFrequent(self, num_map, k):
        q = []
        heapq.heapify(q)
        min_count = float("inf")
        for num in num_map:
            count = num_map[num]
            if len(q) < k:
                heapq.heappush(q, (count, num))
                if min_count > count:
                    min_count = count
            else:
                if min_count >= count:
                    continue
                heapq.heappop(q)
                heapq.heappush(q, (count, num))
                tmp = heapq.heappop(q)
                min_count = tmp[0]
                heapq.heappush(q, tmp)

        return q

if __name__ == "__main__":
    nums = [1, 1, 1, 2, 2, 3]
    sol = Solution()
    res = sol.topKFrequent(nums, 2)
    print(res)