def can_convert_at_once(s1, s2):
    if len(s1) == len(s2):
        return can_convert_by_replace(s1, s2)
    
    if len(s1) > len(s2):
        return can_convert_by_insert(s2, s1)
    
    return can_convert_by_insert(s1, s2)

def can_convert_by_replace(s1, s2):
    count = 0
    for i in range(len(s1)):
        if s1[i] == s2[i]:
            continue
        count += 1
        if count > 1:
            return False
    
    return True

def can_convert_by_insert(shorter, longer):
    pos_diff = 0
    for i in range(len(shorter)):
        if shorter[i] == longer[i + pos_diff]:
            continue
        pos_diff += 1
        if pos_diff > 1:
            return False
    
    return True

if __name__ == '__main__':
    # res = can_convert_at_once("pale", "ple")
    # res = can_convert_at_once("pales", "pale")
    # res = can_convert_at_once("pale", "bale")
    res = can_convert_at_once("pale", "bake")
    print(res)