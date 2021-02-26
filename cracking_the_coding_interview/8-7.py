import copy

def permu_without_dupli(input):
    ans = [""]
    for c in input:
        print(c)
        tmp = copy.copy(ans)
        for s in tmp:
            ans.append(s + c)
    
    return ans

if __name__ == '__main__':
    s = "abc"
    ans = permu_without_dupli(s)
    print(ans)