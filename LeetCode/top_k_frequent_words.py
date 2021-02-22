import heapq

class Solution:
    def topKFrequent(self, words, k):
        word_map = dict()
        for word in words:
            if word not in word_map:
                word_map[word] = 0
            word_map[word] += 1
        
        q = []
        for word in word_map:
            heapq.heappush(q, (-word_map[word], word))
        
        res = []
        for _ in range(k):
            res.append(heapq.heappop(q)[1])
        
        return res