# Divide And Conquer
class Solution(object):
    def longestSubstring(self, s, k):
        if len(s) < k:
            return 0
        if k < 2:
            return len(s)
        if s == "":
            return 0
        countMap = [0 for _ in range(26)]
        for c in s:
            countMap[ord(c) - ord('a')] += 1
        m_cha = None
        for i in range(26):
            if countMap[i] > 0 and countMap[i] < k:
                m_cha = chr(i + ord('a'))
                break
        if m_cha == None:
            return len(s)

        m = len(s)
        for i in range(len(s)):
            if s[i] == m_cha:
                m = i
        
        return max(self.longestSubstring(s[:m], k), self.longestSubstring(s[m+1:], k))

# Sliding Window
class Solution2(object):
    def longestSubstring(self, s, k):
        if len(s) < k:
            return 0
        if k < 2:
            return len(s)
        max_uni = self.countMaxUnique(s)
        result = 0
        for cur_uni in range(1, max_uni + 1):
            win_start, win_end = 0, 0
            unique = 0
            idx = 0
            cur_at_least_k = 0
            cur_map = [0 for _ in range(26)]
            while win_end < len(s):
                if unique <= cur_uni:
                    idx = ord(s[win_end]) - ord('a')
                    if cur_map[idx] == 0:
                       unique += 1
                    cur_map[idx] += 1
                    if cur_map[idx] == k:
                        cur_at_least_k += 1
                    win_end += 1
                else:
                    idx = ord(s[win_start]) - ord('a')
                    if cur_map[idx] == k:
                        cur_at_least_k -= 1
                    cur_map[idx] -= 1
                    if cur_map[idx] == 0:
                        unique -= 1
                    win_start += 1

                if unique == cur_uni and unique == cur_at_least_k:
                    result = max(win_end - win_start, result)
        
        return result
    
    def countMaxUnique(self, s):
        max_uni = 0
        cur_map = [0 for _ in range(26)]
        for c in s:
            idx = ord(c) - ord('a')
            if cur_map[idx] == 0:
                max_uni += 1
            cur_map[idx] += 1
        return max_uni


if __name__ == '__main__':
    sol = Solution()
    s = "aaabb"
    k = 3
    res = sol.longestSubstring(s, k)
    print(res)

    s = "ababbc"
    k = 2
    res = sol.longestSubstring(s, k)
    print(res)

    sol2 = Solution2()
    s = "aaabb"
    k = 3
    res = sol2.longestSubstring(s, k)
    print(res)

    s = "ababbc"
    k = 2
    res = sol2.longestSubstring(s, k)
    print(res)