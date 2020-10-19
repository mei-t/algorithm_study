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