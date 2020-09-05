import sys

class Solution(object):
    def maxProduct(self, nums):
        if len(nums) == 0:
            return None
        max = nums[0]
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
                    max = self.updateMax(max, prod, prod_only_posi)
                    prod = num
                
                elif num < 0:
                    max = self.updateMax(max, prod, prod_only_posi)
                    prod *= num
            
            elif prod == 0:
                max = self.updateMax(max, prod, prod_only_posi)
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
                        max = max(max, prod_only_posi)
                        prod_only_posi = None
                    prod = 0
                elif num < 0:
                    prod *= num
                    prod_only_posi = None
        return max

    def updateMax(self, max, prod, prod_only_posi):
        max = max(max, prod)
        if prod_only_posi == None:
            return max
        prod_only_posi = None
        return max(max, prod_only_posi)