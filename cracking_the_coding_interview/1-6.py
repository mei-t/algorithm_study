def compress_string(s):
    prev = s[0]
    count = 1
    compressed = ""
    for i in range(1, len(s)):
        if s[i] != prev:
            compressed += prev + str(count)
            count = 0
        prev = s[i]
        count += 1
    compressed += prev + str(count)
    return compressed if len(compressed) < len(s) else s

if __name__ == '__main__':
    s = "aabcccccaaa"
    res = compress_string(s)
    print(res)
