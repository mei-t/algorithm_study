def findNeightbors(num):
    pre_i = 1
    is_bottom_one = num & pre_i
    if is_bottom_one:
        while num & pre_i:
            pre_i <<= 1
    else:
        while not (num & pre_i):
            pre_i <<= 1
        pre_i >>= 1
    
    pre = num - pre_i if pre_i < num else None

    nex_i = 1
    is_one_appeared = False
    while not is_one_appeared or (num & nex_i):
        if num & nex_i:
            is_one_appeared = True
        nex_i <<= 1
    
    nex_i >>= 1
    nex = num + nex_i
    
    return pre, nex

if __name__ == "__main__":
    pre, nex = findNeightbors(0b11010)
    print(bin(pre), bin(nex))