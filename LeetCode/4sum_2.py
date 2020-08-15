import unittest

class Solution(object):
    def fourSumCount(self, A, B, C, D):
        num_map = {}
        for a in A:
            for b in B:
                key = -1 * (a + b)
                if key not in num_map:
                    num_map.update({key: 0})
                num_map[key] += 1
        
        ans = 0
        for c in C:
            for d in D:
                key = c + d
                if key in num_map:
                    ans += num_map[key]
                    
        return ans

class Test(unittest.TestCase):
    A = [ 1, 2]
    B = [-2,-1]
    C = [-1, 2]
    D = [ 0, 2]

    def test(self):
        sol = Solution()
        self.assertEqual(sol.fourSumCount(self.A, self.B, self.C, self.D), 2)

if __name__ == '__main__':
    unittest.main()
            