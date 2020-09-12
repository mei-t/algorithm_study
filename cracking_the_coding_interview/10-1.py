def mergeList(a, b):
    a_size = len(a)
    a.extend(b)
    for i in range(len(b)):
        j = i + a_size
        while(j > 0 and a[j] < a[j - 1]):
            a[j-1], a[j] = a[j], a[j-1]
            j -= 1

if __name__ == '__main__':
    a = [0, 2, 5, 7]
    b = [1, 2, 6, 9]
    mergeList(a, b)
    for num in a:
        print(num)
        