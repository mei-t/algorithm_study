class Solution(object):
    def getSum(self, a, b):
        # if not (a & (1 << 31)) ^ (b & (1 << 31)):
        res = 0
        carry = 0
        for i in range(31):
            mask = 1 << i
            carry <<= 1
            a_masked = mask & a
            b_masked = mask & b
            if a_masked ^ b_masked ^ carry:
                res |= mask
            carry = (a_masked & b_masked) | (b_masked & carry) | (carry & a_masked)
            
        return res

if __name__ == '__main__':
    sol = Solution()
    res = sol.getSum(127, 3)
    print(res)