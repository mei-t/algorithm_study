def multiplication(a, b):
    def compute(larger, smaller):
        if smaller == 1:
            return larger

        rest = 0
        if smaller & 1:
            rest += larger
        return compute(larger + larger, smaller >> 1) + rest

    return compute(max(a, b), min(a, b))

if __name__ == '__main__':
    res = multiplication(20, 34)
    print(res)
