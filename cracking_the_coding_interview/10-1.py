def mergeList(a, b):
    a_size = len(a)
    a.extend(b)
    for i in range(len(b)):
        j = i + a_size
        while(j > 0 and a[j] < a[j - 1]):
            a[j-1], a[j] = a[j], a[j-1]
            j -= 1

def mergeListFast(a, b, last_a, last_b):
    index_a = last_a - 1
    index_b = last_b - 1
    index_merged = last_a + last_b - 1

    while index_b >= 0:
        print(index_a, index_b, index_merged)
        if index_a >= 0 and a[index_a] > b[index_b]:
            a[index_merged] = a[index_a]
            index_a -= 1
        else:
            a[index_merged] = b[index_b]
            index_b -= 1
        
        index_merged -= 1


if __name__ == '__main__':
    a = [0, 2, 5, 7, None, None, None, None, None, None]
    b = [1, 2, 6, 9]
    mergeListFast(a, b, 4, 4)
    for num in a:
        print(num)
        