class Node:
    def __init__(self, project, count=0):
        self.project = project
        self.count = count
        self.nexts = []

def delete_node(node, project_map):
    for p in node.nexts:
        project_map[p].count -= 1
    node.count -= 1

def executive_order(projects, dependencies):
    project_map = dict()
    for project in projects:
        project_map[project] = Node(project)
        print(project_map[project].count)

    for d in dependencies:
        project_map[d[0]].count += 1
        print(project_map[d[0]].count)
        project_map[d[1]].nexts.append(d[0])
    
    
    res = []
    while len(res) < len(projects):
        for project in project_map:
            node = project_map[project]
            if node.count == 0:
                res.append(node.project)
                delete_node(node, project_map)
    
    return res

if __name__ == '__main__':
    projects = ["a", "b", "c", "d", "e", "f"]
    dependencies = [("d", "a"), ("b", "f"), ("d", "b"), ("a", "f"), ("c", "d")]
    res = executive_order(projects, dependencies)
    print(res)