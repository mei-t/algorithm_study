# 10:05
class Solution:
    def countAndSay(self, n):
        if n == 1:
            return "1"
        prev_s = self.countAndSay(n - 1)
        prev = ''
        count = 1
        res = []
        for i in range(len(prev_s)):
            if prev == prev_s[i]:
                count += 1
                continue
            if prev != '':
                res.append(str(count) + str(prev))
            prev = prev_s[i]
            count = 1
        res.append(str(count) + str(prev))
        return ''.join(res)