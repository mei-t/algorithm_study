class Solution(object):
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
    sol = Solution()
    res = sol.uniquePaths(1, 10)
    print(res)