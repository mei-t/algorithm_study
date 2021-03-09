import collections

def permu_with_dupli(s):
    d = collections.Counter(s)
    res = []
    create_permu(res, d, '', len(s))
    return res

def create_permu(res, d, prefix, remain):
    if remain == 0:
        res.append(prefix)
        return
    
    for c in d:
        if d[c] <= 0:
            continue
        d[c] -= 1
        create_permu(res, d, prefix + c, remain - 1)
        d[c] += 1

if __name__ == '__main__':
    res = permu_with_dupli('abcbbac')
    print(res)