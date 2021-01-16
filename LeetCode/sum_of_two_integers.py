# class Solution1(object):
#     def getSum(self, a, b):
#         # if not (a & (1 << 31)) ^ (b & (1 << 31)):
#         res = 0
#         carry = 0
#         for i in range(32):
#             mask = 1 << i
#             carry <<= 1
#             a_masked = mask & a
#             b_masked = mask & b
#             if a_masked ^ b_masked ^ carry:
#                 res |= mask
#             carry = (a_masked & b_masked) | (b_masked & carry) | (carry & a_masked)
            
#         return res

class Solution(object):
    def getSum(self, a, b):
        carry = a & b
        ans = a ^ b
        digit = 0
        while carry and digit < 32:
            carry <<= 1
            tmp = ans ^ carry
            carry = ans & carry
            ans = tmp
            digit += 1
        
        mask = 0xFFFFFFFF
        
        return ans if digit < 32 else ans & mask

if __name__ == '__main__':
    sol = Solution()
    res = sol.getSum(-1, 1)
    print(res)