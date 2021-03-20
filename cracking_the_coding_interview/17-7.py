def merge(repre, name, name_to_repre, repre_to_name):
    for n in repre_to_name[name]:
        name_to_repre[n] = repre
        repre_to_name[repre].append(n)
    del repre_to_name[name]

def create_name_list(names, synonyms):
    name_to_repre = dict()
    repre_to_name = dict()
    for s in synonyms:
        if s[0] in name_to_repre and s[1] in name_to_repre:
            if name_to_repre[s[0]] == name_to_repre[s[1]]:
                continue
            merge(name_to_repre[s[0]], name_to_repre[s[1]], name_to_repre, repre_to_name)
            continue
        if s[0] in name_to_repre:
            repre = name_to_repre[s[0]]
            name_to_repre[s[1]] = repre
            repre_to_name[repre].append(s[1])
        elif s[1] in name_to_repre:
            repre = name_to_repre[s[1]]
            name_to_repre[s[0]] = repre
            repre_to_name[repre].append(s[0])
        else:
            name_to_repre[s[0]] = s[0]
            name_to_repre[s[1]] = s[0]
            repre_to_name[s[0]] = [s[0], s[1]]
    
    res = dict()
    for repre in repre_to_name:
        res[repre] = 0
        for name in repre_to_name[repre]:
            if name in names:
                res[repre] += names[name]
    
    return res

if __name__ == '__main__':
    names = {"John": 15, "Jon": 12, "Chris": 13, "Kris": 4, "Christopher": 19}
    synonyms = [["Jon", "John"], ["John", "Johnny"], ["Chris", "Kris"], ["Chris", "Christopher"]]
    res = create_name_list(names, synonyms)
    print(res)