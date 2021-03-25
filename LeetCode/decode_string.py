# 42:14
class Solution:
    def decodeString(self, s):
        stack = []
        idx = 0
        res = ''
        while idx < len(s):
            if s[idx] == ']':
                tmp = stack.pop()
                rep_str = ''
                while type(tmp) is str:
                    rep_str = tmp + rep_str
                    tmp = stack.pop()
                rep_count = tmp
                sub_str = (rep_str * rep_count)
                idx += 1
                if not stack:
                    res += sub_str
                else:
                    stack.append(sub_str)
            elif ord('0') <= ord(s[idx]) <= ord('0') + 9:
                num = int(s[idx])
                idx += 1
                while ord('0') <= ord(s[idx]) <= ord('0') + 9:
                    num *= 10
                    num += int(s[idx])
                    idx += 1
                stack.append(num)
            elif s[idx] == '[' or stack:
                if s[idx] == '[':
                    idx += 1
                tmp = idx
                while s[idx] != ']' and s[idx] != '[' and not ord('0') <= ord(s[idx]) <= ord('0') + 9:
                    idx += 1
                stack.append(s[tmp:idx])
            else:
                res += s[idx]
                idx += 1
        return res