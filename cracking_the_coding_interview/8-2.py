from enum import Enum
import copy

class Direction(Enum):
    RIGHT = 1
    DOWN = 2

def findRoot(matrix):
    if len(matrix) == 0:
        return []
    root, res = [], []
    checkNext(matrix, 0, 0, [], res)
    return res

def checkNext(matrix, i, j, root, res):
    r = len(matrix)
    c = len(matrix[0])
    if i >= r or j >= c or not matrix[i][j]:
        return False
    
    if i == r - 1 and j == c - 1:
        res.append(root)
        return True

    right_root = copy.deepcopy(root)
    right_root.append(Direction.RIGHT)
    down_root = copy.deepcopy(root)
    down_root.append(Direction.DOWN)
    checkNext(matrix, i, j+1, right_root, res)
    checkNext(matrix, i+1, j, down_root, res)

def findRoot2(matrix):
    if not matrix:
        return None
    isVisited = [[False for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
    root = []
    if getRoot(matrix, len(matrix) - 1, len(matrix[0]) - 1, root, isVisited):
        return root
    return None

def getRoot(matrix, r, c, root, isVisited):
    if r < 0 or c < 0 or not matrix[r][c]:
        return False

    if isVisited[r][c]:
        return False
    
    if (r == 0 and c == 0) or getRoot(matrix, r - 1, c, root, isVisited) or getRoot(matrix, r, c - 1, root, isVisited):
        root.append((r, c))
        return True
    
    isVisited[r][c] = True
    return False
    


if __name__ == '__main__':
    matrix = [
        [1, 1, 1, 1],
        [0, 1, 0, 1],
        [0, 1, 1, 1]
    ]
    res = findRoot(matrix)
    print(res)