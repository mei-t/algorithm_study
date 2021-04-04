def count(people, ht, wt, i, tower_map):
    if i == len(people):
        return 0
    
    if (ht, wt, i) in tower_map:
        return tower_map[ht, wt, i]
    
    res = 0
    for j in range(i, len(people)):
        next_ht = people[j][0]
        next_wt = people[j][1]
        if next_ht > ht and next_wt > wt:
            res = max(res, count(people, next_ht, next_wt, j + 1, tower_map) + 1)
    
    tower_map[ht, wt, i] = res
    return res

def circus_tower(people):
    people.sort()
    return count(people, 0, 0, 0, dict())

if __name__ == '__main__':
    people = [(65, 100), (70, 150), (56, 90), (75, 190), (60, 95), (68, 110)]
    print(circus_tower(people))
