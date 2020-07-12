import unittest

GRID_SIZE = 8

def isValid(row, col, columns):
    for i in range(row):
        if col == columns[i] or row - i == col - columns[i]:
            return False
    return True

def place_queen_row(row, columns, results):
    if row < GRID_SIZE:
        for col in range(GRID_SIZE):
            if not isValid(row, col, columns):
                continue
            columns[row] = col
            place_queen_row(row + 1, columns, results)
    else:
        results.append([columns.copy()])
    return results

def place_queen():
    columns = [0 for i in range(GRID_SIZE)]
    results = []
    return place_queen_row(0, columns, results)

if __name__ == '__main__':
    res = place_queen()
    print(len(res))
    for tmp in res:
        print(tmp)