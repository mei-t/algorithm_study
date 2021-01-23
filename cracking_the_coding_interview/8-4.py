import copy

def partial_collection(nums):
    pcs = [[]]
    for num in nums:
        tmp = copy.copy(pcs)
        for pc in tmp:
            new_pc = copy.copy(pc)
            new_pc.append(num)
            pcs.append(new_pc)
        
    return pcs

if __name__ == "__main__":
    nums = [1, 2, 3]
    res = partial_collection(nums)
    print(res)