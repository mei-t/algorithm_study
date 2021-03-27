def brackets_arrangement(n):
    res = []
    check(n, n, '', res)
    return res

def check(op, cl, cur, res):
    if cl == 0:
        res.append(cur)
    elif op == 0:
        cur += ')'
        check(op, cl - 1, cur, res)
    elif op == cl:
        cur += '('
        check(op - 1, cl, cur, res)
    else:
        check(op - 1, cl, cur + '(', res)
        check(op, cl - 1, cur + ')', res)

if __name__ == '__main__':
    res = brackets_arrangement(3)
    print(res)