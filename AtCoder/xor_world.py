# 16:20
def xor(x):
    if x % 4 == 0:
        return x
    if x % 4 == 1:
        return 1
    if x % 4 == 2:
        return x + 1
    if x % 4 == 3:
        return 0

if __name__ == '__main__':
    a, b = map(int, input().split())
    xor_prev_a = xor(a - 1)
    xor_b = xor(b)
    print(xor_prev_a ^ xor_b)