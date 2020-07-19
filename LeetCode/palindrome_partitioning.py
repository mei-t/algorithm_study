import unittest
import copy

class Solution(object):
    def partition(self, s):
        res = []
        self.dfs(s, [], res)
        return res


    def dfs(self, s, partition, res):
        if not s:
            res.append(partition)
            return
        
        for i in range(1, len(s) + 1):
            if self.isPalind(s[:i]):
                self.dfs(s[i:], partition + [s[:i]], res)


    def isPalind(self, s):
        return s == s[::-1]

if __name__ == '__main__':
    s = "abbab"
    sol = Solution()
    ans = sol.partition(s)
    print(ans)