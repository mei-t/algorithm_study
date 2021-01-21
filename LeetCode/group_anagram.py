from collections import defaultdict

class Solution1(object):
    def groupAnagrams(self, strs):
        str_map = dict()
        for s in strs:
            sorted_s = "".join(sorted(s))
            if sorted_s not in str_map:
                str_map[sorted_s] = []
            str_map[sorted_s].append(s)
        
        res = []
        for ss in str_map:
            res.append(str_map[ss])
        
        return res

class Solution(object):
    def groupAnagrams(self, strs):
        ans = defaultdict(list)
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord("a")] += 1
            ans[tuple(count)].append(s)
        
        return ans.values()

if __name__ == "__main__":
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    sol = Solution()
    res = sol.groupAnagrams(strs)
    print(res)