class Solution3(object):
    def uniquePaths(self, m, n):
        dp = [[1 for _ in range(n)] for _ in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i][j-1] + dp[i-1][j]
        
        return dp[m-1][n-1]

class Solution2(object):
    def uniquePaths(self, m, n):
        m -= 1
        n -= 1
        nume, deno = 1, 1
        for i in range(min(m, n)):
            nume = nume * (m + n - i)
            deno = deno * (min(m, n) - i)
        return int(nume / deno)

class Solution1(object):
    def uniquePaths(self, m, n):
        if m == 1 or n == 1:
            return 1
        nume = self.factorial(m + n - 2, max(m, n))
        deno = self.factorial(min(m, n) - 1)
        return nume // deno
    
    def factorial(self, num, min_num=1):
        if num <= min_num:
            return min_num
        return self.factorial(num - 1, min_num) * num

if __name__ == "__main__":
    sol = Solution3()
    res = sol.uniquePaths(3, 7)
    print(res)