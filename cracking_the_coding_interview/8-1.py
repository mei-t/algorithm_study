def count_ways(k, map):
    if k in map:
        return map[k]
    if k < 0:
        return 0
    if k == 0:
        return 1
    map[k] = triple_step(k - 1) + triple_step(k - 2) + triple_step(k - 3)
    return map[k]

def triple_step(k):
    return count_ways(k, dict())

if __name__ == '__main__':
    print(triple_step(3))