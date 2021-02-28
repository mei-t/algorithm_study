import sys

def sign(a):
    return ((a >> (sys.getsizeof(a) - 1)) & 1) ^ 1

def get_max(a, b):
    k = sign(a - b)
    return a * k + b * (k ^ 1)

if __name__ == '__main__':
    res = get_max(-16, -3)
    print(res)