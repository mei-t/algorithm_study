# 5:36
if __name__ == '__main__':
    s = input()
    count = 0
    for i in range(len(s)):
        if i % 2:
            count += 1 if s[i] == '1' else 0
        else:
            count += 1 if s[i] == '0' else 0
    print(min(count, len(s) - count))