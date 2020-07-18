import unittest
import copy

class Solution(object):
    def partition(self, s):
        palind_dict = {}
        for i in range(len(s)):
            for j in range(i+1, len(s)):
                if self.isPalind(i, j, s):
                    if s[i] not in palind_dict:
                        palind_dict[s[i]] = []
                    palind_dict[s[i]].append([i, j])
        
        partitions = [[0, []]]
        for i in range(len(s)):
            for partition in partitions:
                if i != partition[0]:
                    continue
                for palind in palind_dict[s[i]]:
                    import pdb; pdb.set_trace()
                    partition_copy = copy.copy(partition)
                    import pdb; pdb.set_trace()
                    partition_copy[0] = palind[1] + 1
                    import pdb; pdb.set_trace()
                    partition_copy[1].append(s[palind[0] : (palind[1] + 1)])
                    import pdb; pdb.set_trace()
                    partitions.append(partition_copy)
                
                import pdb; pdb.set_trace()
                partition[0] = i
                partition[1].append(s[i])

        ans = []
        for partition in partitions:
            ans.append(partition[1])
        return ans


    def isPalind(self, start, end, s):
        left = start
        right = end

        while(left < right):
            if(s[left] != s[right]):
                return False
            left += 1
            right -= 1
        
        return True

# class Test(unittest.TestCase):
#     s = "abbab"

if __name__ == '__main__':
    s = "abbab"
    sol = Solution()
    ans = sol.partition(s)
    print(ans)