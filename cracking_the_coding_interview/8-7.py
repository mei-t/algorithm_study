import copy

def permu_without_dupli(input):
    prev = [""]
    for i, c in enumerate(input):
        ans = []
        for s in prev:
            for j in range(i + 1):
                ans.append(s[:j] + c + s[j:])
        prev = ans
    
    return ans

if __name__ == '__main__':
    s = "abc"
    ans = permu_without_dupli(s)
    print(ans)