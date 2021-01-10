class Solution(object):
    def myPow(self, x, n):
        if n == 0:
            return 1

        x = (1 / x) if n < 1 else x
        n = -1 * n if n < 1 else n
        num = x
        quotient = 2
        num_map = {1: x}
        while quotient <= n:
            num *= num
            num_map[quotient] = num
            quotient *= 2
        quotient /= 2
        res = 1
        while n > 0:
            while n < quotient:
                quotient /= 2
            res *= num_map[quotient]
            n -= quotient
        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.myPow(2.00000, 2))
    print(sol.myPow(2.00000, 10))
    print(sol.myPow(2.10000, 3))
    print(sol.myPow(2.00000, -2))
    print(sol.myPow(42.38803, 1))