def exchange_bit_pair(input):
    tmp = input
    even_mask, odd_mask = 0, 0
    while tmp:
        even_mask <<= 2
        odd_mask <<= 2
        even_mask |= 1
        odd_mask |= 2
        tmp >>= 2
    return ((input & even_mask) << 1) | ((input & odd_mask) >> 1)

if __name__ == '__main__':
    res = exchange_bit_pair(10)
    print(res)
