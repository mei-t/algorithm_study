# Better
class Solution:
    def longestLine(self, M):
        if not M:
            return 0
        
        max_line = 0
        row = len(M)
        col = len(M[0])
        
        dp = [[[0] * 4 for _ in range(col)] for _ in range(row)]
        for i in range(row):
            for j in range(col):
                if M[i][j]:
                    dp[i][j][0] = dp[i - 1][j][0] + 1 if i > 0 else 1
                    dp[i][j][1] = dp[i][j - 1][1] + 1 if j > 0 else 1
                    dp[i][j][2] = dp[i - 1][j - 1][2] + 1 if i > 0 and j > 0 else 1
                    dp[i][j][3] = dp[i - 1][j + 1][3] + 1 if i > 0 and j < col - 1 else 1
                    max_line = max(max_line, max(dp[i][j]))
        return max_line

class Solution1:
    def longestLine(self, M):
        if not M:
            return 0
        
        max_line = 0
        row = len(M)
        col = len(M[0])
        for i in range(row):
            cur_line = 0
            for j in range(col):
                if M[i][j]:
                    cur_line += 1
                else:
                    max_line = max(max_line, cur_line)
                    cur_line = 0
            max_line = max(max_line, cur_line)
        
        for i in range(col):
            cur_line = 0
            for j in range(row):
                if M[j][i]:
                    cur_line += 1
                else:
                    max_line = max(max_line, cur_line)
                    cur_line = 0
            max_line = max(max_line, cur_line)

        # UpperとLowerで分けるともう少し簡単になりそう    
        for i in range(-row + 1, col):
            j = max(0, -i)
            cur_line = 0
            while j < row and j + i < col:
                if M[j][j + i]:
                    cur_line += 1
                else:
                    max_line = max(max_line, cur_line)
                    cur_line = 0
                j += 1
            max_line = max(max_line, cur_line)
        
        for i in range(-col + 1, row):
            j = max(0, i)
            cur_line = 0
            while j < row and j - i < col:
                if M[j][col - j + i -1]:
                    cur_line += 1
                else:
                    max_line = max(max_line, cur_line)
                    cur_line = 0
                j += 1
            max_line = max(max_line, cur_line)
        
        return max_line