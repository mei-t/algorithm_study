# 14:43

if __name__ == '__main__':
    n, q = map(int, input().split())
    s = input()
    lefts, rights = [], []
    for i in range(q):
        l, r = map(int, input().split())
        lefts.append(l)
        rights.append(r)
    
    counts = [0]
    count = 0
    for i in range(1, n):
        if s[i - 1: i + 1] == 'AC':
            count += 1
        counts.append(count)

    for l, r in zip(lefts, rights):
        print(counts[r - 1] - counts[l - 1])