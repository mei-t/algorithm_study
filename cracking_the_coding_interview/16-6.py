def find_min_diff(a, b):
    a.sort()
    b.sort()
    a_pos = 0
    b_pos = 0
    min_diff = float("inf")
    while a_pos < len(a) and b_pos < len(b):
        min_diff = min(abs(a[a_pos] - b[b_pos]), min_diff)
        if (a_pos < len(a) - 1 and a[a_pos] < b[b_pos]) or b_pos >= len(b) - 1:
            a_pos += 1
        else:
            b_pos += 1
    
    return min_diff

if __name__ == '__main__':
    a = [1, 3, 15, 11, 2]
    b = [23, 127, 235, 19, 8]
    res = find_min_diff(a, b)
    print(res)
