class Solution1(object):
    def coinChange(self, coins, amount):
        coins.sort(reverse=True)
        return self.computeChange(coins, amount, 0, None, 0)
    
    def computeChange(self, coins, amount, i, min_count, cur):
        if min_count and min_count <= cur:
            return cur

        if i >= len(coins):
            return -1
        
        if amount == 0:
            return cur
        
        if coins[i] > amount:
            return self.computeChange(coins, amount, i + 1, min_count, cur)
        
        if i == len(coins) - 1:
            if amount % coins[i]:
                return -1
            else:
                return cur + amount // coins[i]
        
        in_res = self.computeChange(coins, amount - coins[i], i, min_count, cur + 1)
        if in_res != -1:
            min_count = min(min_count, in_res) if min_count else in_res
        ex_res = self.computeChange(coins, amount, i + 1, min_count, cur)
        if ex_res != -1:
            min_count = min(min_count, ex_res) if min_count else ex_res

        if in_res == -1 and ex_res == -1:
            return -1
        return min_count

class Solution2(object):
    def coinChange(self, coins, amount):
        if amount < 1:
            return 0
        count = [0 for _ in range(amount)]
        return self.computeChange(coins, amount, count)
    
    def computeChange(self, coins, amount, count):
        if amount < 0:
            return -1
        if amount == 0:
            return 0
        if count[amount - 1] != 0:
            return count[amount - 1]
        min_res = None
        for coin in coins:
            res = self.computeChange(coins, amount - coin, count)
            if res >= 0 and (min_res == None or min_res > res):
                min_res = res + 1
        
        count[amount - 1] = -1 if min_res == None else min_res
        return count[amount - 1]

class Solution(object):
    def coinChange(self, coins, amount):
        dp = [float("inf")] * (amount + 1)
        dp[0] = 0

        for coin in coins:
            for x in range(coin, amount + 1):
                dp[x] = min(dp[x], dp[x - coin] + 1)
        
        return dp[amount] if dp[amount] < float("inf") else -1


if __name__ == '__main__':
    # coins = [1, 2, 5]
    sol = Solution()
    # res = sol.coinChange([2], 3)
    # # res = sol.coinChange(coins, 11)
    coins = [186, 419, 83, 408]
    res = sol.coinChange(coins, 6249)
    print(res)