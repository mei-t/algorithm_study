def sort_stack(s):
    if not s:
        return
    
    sorted_s = [s.pop()]
    temp_s = []

    while s:
        cur = s.pop()
        while sorted_s and sorted_s[-1] > cur:
            temp_s.append(sorted_s.pop())
        sorted_s.append(cur)
        while temp_s:
            sorted_s.append(temp_s.pop())
        
    while sorted_s:
        s.append(sorted_s.pop())

if __name__ == '__main__':
    nums = [0]
    s = [4, 45, 6, 72, 0, 25]
    sort_stack(s)
    print(s)