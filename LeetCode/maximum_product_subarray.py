import sys

class Solution(object):
    def maxProduct(self, nums):
        if len(nums) == 0:
            return None
        max_prod = nums[0]
        prod = None
        prod_only_posi = None
        for num in nums:
            if prod == None:
                prod = num
            elif prod > 0:
                if num > 0:
                    prod *= num
                    if prod_only_posi != None:
                        prod_only_posi *= num
                    
                elif num == 0:
                    max_prod, prod_only_posi = self.updateMax(max_prod, prod, prod_only_posi)
                    prod = num
                
                elif num < 0:
                    max_prod, prod_only_posi = self.updateMax(max_prod, prod, prod_only_posi)
                    prod *= num
            
            elif prod == 0:
                max_prod, prod_only_posi = self.updateMax(max_prod, prod, prod_only_posi)
                prod = num
            
            elif prod < 0:
                if num > 0:
                    if prod_only_posi != None:
                        prod_only_posi *= num
                    else:
                        prod_only_posi = num
                    prod *= num
                elif num == 0:
                    if prod_only_posi != None:
                        max_prod = max(max_prod, prod_only_posi)
                        prod_only_posi = None
                    prod = 0
                elif num < 0:
                    prod *= num
                    prod_only_posi = None
        max_prod, prod_only_posi = self.updateMax(max_prod, prod, prod_only_posi)
        return max_prod

    def updateMax(self, max_prod, prod, prod_only_posi):
        max_prod = max(max_prod, prod)
        if prod_only_posi == None:
            return max_prod
        return max(max_prod, prod_only_posi), None

if __name__ == '__main__':
    nums = [2,3,-2,4]
    sol = Solution()
    print("aaa")
    print(sol.maxProduct(nums))