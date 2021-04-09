def is_valid(c1, c2, c3, a):
    if c2 == 0 and c1 == 1 and a == 2:
        return False
    if c2 == 0 and c1 == 2 and a == 1:
        return False
    if c2 == 1 and c1 == 0 and a == 2:
        return False
    if c3 == 0 and c1 == 1 and a == 2:
        return False
    if c3 == 0 and c2 == 1 and a == 2:
        return False

    return True

if __name__ == '__main__':
    n = int(input())
    mod = 1000000007
    dp = [[[[0] * 4 for _ in range(4)] for _ in range(4)] for _ in range(101)]
    dp[0][3][3][3] = 1
    for length in range(n):
        for c1 in range(4):
            for c2 in range(4):
                for c3 in range(4):
                    if dp[length][c1][c2][c3] == 0:
                        continue
                    for a in range(4):
                        if not is_valid(c1, c2, c3, a):
                            continue
                        dp[length + 1][a][c1][c2] += dp[length][c1][c2][c3]
                        dp[length + 1][a][c1][c2] %= mod
    
    ans = 0
    for c1 in range(4):
        for c2 in range(4):
            for c3 in range(4):
                ans += dp[n][c1][c2][c3]
                ans %= mod
    print(ans)