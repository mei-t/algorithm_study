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

if __name__ == '__main__':
    matrix = [
        [1, 1, 1, 1],
        [0, 1, 0, 1],
        [0, 1, 1, 1]
    ]
    res = findRoot(matrix)
    print(res)