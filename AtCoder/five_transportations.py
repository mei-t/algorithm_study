# 12:03
if __name__ == '__main__':
    N, A, B, C, D, E = int(input()), int(input()), int(input()), int(input()), int(input()), int(input())
    x = min(A, B, C, D, E)
    if N == 0:
        print(0)
    else:
        print(4 + (N + x - 1) // x)