class Solution(object):
    def numSquares(self, n):
        if n == 1:
            return n

        i = 1
        l = []
        while i ** 2 <= n:
            l.append(i**2)
            i += 1
        
        to_check = {n}
        count = 0
        while to_check:
            count += 1
            tmp = set()
            for num in to_check:
                for i in l:
                    if num == i:
                        return count
                    if num < i:
                        break
                    tmp.add(num - i)
            to_check = tmp
        return count

class Solution1(object):
    def numSquares(self, n):
        sq = self.findMaxSquare(n)
        return self.findSquareSet(n, sq, 0, None)

    def findMaxSquare(self, n):
        sq = n // 2 if n > 2 else 1
        while sq**2 > n:
            sq -= 1
        return sq

    def findSquareSet(self, n, sq, cur, cand):
        if n == sq**2:
            return 1 + cur

        if sq == 1:
            return n + cur

        if cand and cand <= cur:
            return cand

        include_sq = self.findSquareSet(n - sq**2, sq, cur + 1, None) if n > sq**2 else None
        skip_sq = self.findSquareSet(n, sq - 1, cur, include_sq)
        if not include_sq or include_sq > skip_sq:
            return skip_sq
        return include_sq

if __name__ == '__main__':
    sol = Solution()
    res = sol.numSquares(2)
    print(res)
