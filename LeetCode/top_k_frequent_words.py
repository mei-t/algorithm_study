import heapq, collections

class Solution:
    def topKFrequent(self, words, k):
        word_map = collections.Counter(words)
        candidates = list(word_map.keys())
        candidates.sort(key = lambda w: (-word_map[w], w))
        return candidates[:k]

class Solution1:
    def topKFrequent(self, words, k):
        # word_map = dict()
        # for word in words:
        #     if word not in word_map:
        #         word_map[word] = 0
        #     word_map[word] += 1
        word_map = collections.Counter(words)
        
        q = []
        for word in word_map:
            heapq.heappush(q, (-word_map[word], word))
        
        res = []
        for _ in range(k):
            res.append(heapq.heappop(q)[1])
        
        return res