def triple_step(k):
    if k < 0:
        return 0
    if k == 0:
        return 1
    return triple_step(k - 1) + triple_step(k - 2) + triple_step(k - 3)

if __name__ == '__main__':
    print(triple_step(6))