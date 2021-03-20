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

class Graph:
    def __init__(self, name, count=0, is_visited=False, next=None):
        self.name = name
        self.count = count
        self.is_visited = is_visited
        self.next = next
        self.neighbors = []

def create_new_graph(names, i, name_map):
    if i >= len(names):
        return None
    
    graph = Graph(names[i][0], names[i][1])
    graph.next = create_new_graph(names, i + 1, name_map)
    name_map[names[i][0]] = graph
    return graph

def create_name_list2(names, synonyms):
    names = list(names.items())
    name_map = dict()
    root = create_new_graph(names, 0, name_map)

    for synonym in synonyms:
        if synonym[0] not in name_map:
            name_map[synonym[0]] = Graph(synonym[0])
        if synonym[1] not in name_map:
            name_map[synonym[1]] = Graph(synonym[1])
        
        name_map[synonym[0]].neighbors.append(name_map[synonym[1]])
        name_map[synonym[1]].neighbors.append(name_map[synonym[0]])
    
    res = dict()
    current = root
    while current:
        if current.is_visited:
            current = current.next
            continue

        current.is_visited = True
        res[current.name] = current.count
        for neighbor in current.neighbors:
            if neighbor.is_visited:
                continue
            neighbor.is_visited = True
            res[current.name] += neighbor.count

        current = current.next
    return res
    
if __name__ == '__main__':
    names = {"John": 15, "Jon": 12, "Chris": 13, "Kris": 4, "Christopher": 19}
    synonyms = [["Jon", "John"], ["John", "Johnny"], ["Chris", "Kris"], ["Chris", "Christopher"]]
    res = create_name_list2(names, synonyms)
    print(res)