def bit_convertion(a, b):
    mask = 1
    count = 0
    while mask <= max(a, b):
        if (a & mask) != (b & mask):
            count += 1
        mask <<= 1

    return count

if __name__ == '__main__':
    res = bit_convertion(29, 15)
    print(res)