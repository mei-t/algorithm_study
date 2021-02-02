def count_zero(n):
    count = 0
    i = 5
    while n // i:
        count += n // i
        i *= 5
    
    return count

if __name__ == '__main__':
    res = count_zero(25)
    print(res)
