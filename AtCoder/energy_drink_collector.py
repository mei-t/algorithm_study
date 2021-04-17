# 7:43
if __name__ == '__main__':
    n, m = map(int, input().split())
    shop = []
    for _ in range(n):
        shop.append(list(map(int, input().split())))
    shop.sort()
    res = 0
    i = 0
    while m:
        num = min(m, shop[i][1])
        res += num * shop[i][0]
        m -= num
        i += 1
    print(res)