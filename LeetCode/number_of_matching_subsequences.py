# TLE
def char_to_num(c):
    return ord(c) - ord('a')

class TrieNode:
    def __init__(self,):
        self.next = [None] * 26

class Solution:
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