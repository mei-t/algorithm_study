class Solution:
    def numMatchingSubseq(self, s, words):
        heads = [[] for _ in range(26)]
        for word in words:
            it = iter(word)
            heads[ord(next(it)) - ord('a')].append(it)
        
        ans = 0
        for c in s:
            idx = ord(c) - ord('a')
            tmp = heads[idx]
            heads[idx] = []
            while tmp:
                it = tmp.pop()
                nxt = next(it, None)
                if not nxt:
                    ans += 1
                    continue
                heads[ord(nxt) - ord('a')].append(it)
        return ans

# TLE
class Solution3:
    def numMatchingSubseq(self, s, words):
        def subseq(word):
            it = iter(s)
            return all(x in it for x in word)
        
        return sum(subseq(word) for word in words)

# TLE
class Solution2:
    def numMatchingSubseq(self, s, words):
        count = 0
        for word in words:
            word_i = 0
            s_i = 0
            while s_i < len(s):
                if word[word_i] == s[s_i]:
                    word_i += 1
                    if word_i == len(word):
                        count += 1
                        break
                s_i += 1
        
        return count

# TLE
def char_to_num(c):
    return ord(c) - ord('a')

class TrieNode:
    def __init__(self,):
        self.next = [None] * 26

class Solution1:
    def numMatchingSubseq(self, s, words):
        root = TrieNode()
        prevs = [root]
        for c in s:
            i = char_to_num(c)
            curs = []
            for prev in prevs:
                if not prev.next[i]:
                    prev.next[i] = TrieNode()
                    curs.append(prev.next[i])
            prevs.extend(curs)
        
        count = 0
        for word in words:
            node = root
            for i in range(len(word)):
                idx = char_to_num(word[i])
                if not node.next[idx]:
                    break
                if i == len(word) - 1:
                    count += 1
                node = node.next[idx]
        return count