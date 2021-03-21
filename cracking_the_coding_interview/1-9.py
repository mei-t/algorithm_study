def is_substring(s1, s2):
    return s2 in s1

def is_rotated(s1, s2):
    s1_double = s1 + s1
    return is_substring(s1_double, s2) and len(s1) == len(s2)

if __name__ == '__main__':
    res = is_rotated("waterbottle", "erbottlewat")
    print(res)