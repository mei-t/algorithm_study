import unittest

class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

# 平行な場合を考えない
def find_intersection(p11, p12, p21, p22):
    is_vertical1 = False
    is_vertical2 = False
    if p11.x == p12.x:
        x = p11.x
        is_vertical1 = True
    else:
        a1 = (p11.y - p12.y) / (p11.x - p12.x)
        b1 = (p11.x * p12.y - p12.x * p11.y) / (p11.x - p12.x)

    if p21.x == p22.x:
        x = p21.x
        is_vertical2 = True
    else:
        a2 = (p21.y - p22.y) / (p21.x - p22.x)
        b2 = (p21.x * p22.y - p22.x * p21.y) / (p21.x - p22.x)

    if not is_vertical1 and not is_vertical2:
        x = (-b1 + b2) / (a1 - a2)
    y = a1 * x + b1 if not is_vertical1 else a2 * x + b2

    min_x1 = min(p11.x, p12.x)
    min_x2 = min(p21.x, p22.x)
    max_x1 = max(p11.x, p12.x)
    max_x2 = max(p21.x, p22.x)
    min_y1 = min(p11.y, p12.y)
    min_y2 = min(p21.y, p22.y)
    max_y1 = max(p11.y, p12.y)
    max_y2 = max(p21.y, p22.y)
    if max(min_x1, min_x2) <= x and x <= min(max_x1, max_x2) and\
        max(min_y1, min_y2) <= y and y <= min(max_y1, max_y2):
        return Point(x, y)
    
    return None

class Test(unittest.TestCase):
    def test_simple(self):
        p11 = Point(-3, -3)
        p12 = Point(0, 3)
        p21 = Point(-4, 0)
        p22 = Point(2, -6)
        res = find_intersection(p11, p12, p21, p22)
        self.assertAlmostEqual(res.x, -7/3)
        self.assertAlmostEqual(res.y, -5/3)
    
    def test_vertival_case(self):
        p11 = Point(2, -3)
        p12 = Point(2, 3)
        p21 = Point(0, 1)
        p22 = Point(4, 3)
        res = find_intersection(p11, p12, p21, p22)
        self.assertEqual(res.x, 2)
        self.assertEqual(res.y, 2)

if __name__ == '__main__':
    unittest.main()