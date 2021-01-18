def isPalindrome(s):
    char_map = dict()
    for c in s.lower().replace(" ", ""):
        if c not in char_map:
            char_map[c] = 0
        char_map[c] += 1
    
    odd_count = 0
    for c in char_map:
        if char_map[c] % 2:
            odd_count += 1
            if odd_count > 1:
                return False
    return True

if __name__ == '__main__':
    print(isPalindrome("Tact Coa"))