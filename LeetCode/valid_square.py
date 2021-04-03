import math

# 37:23
class Solution:
    def validSquare(self, p1, p2, p3, p4):
        points = [p1, p2, p3, p4]
        points.sort()
        
        len0 = math.sqrt((points[0][0] - points[1][0]) ** 2 + (points[0][1] - points[1][1]) ** 2)
        len1 = math.sqrt((points[0][0] - points[2][0]) ** 2 + (points[0][1] - points[2][1]) ** 2)
        len2 = math.sqrt((points[1][0] - points[3][0]) ** 2 + (points[1][1] - points[3][1]) ** 2)
        len3 = math.sqrt((points[2][0] - points[3][0]) ** 2 + (points[2][1] - points[3][1]) ** 2)
        if not len0 == len1 == len2 == len3:
            return False
        
        if points[0][0] == points[1][0]:
            if points[0][0] != points[1][0]:
                return False
            if points[0][1] != points[2][1]:
                return False
            if points[1][1] != points[3][1]:
                return False
            if points[2][0] != points[3][0]:
                return False
            if points[0][0] == points[2][0]:
                return False
            if points[0][1] == points[1][1]:
                return False
            return True
        
        if points[0][0] == points[2][0] or points[1][0] == points[3][0] or points[2][0] == points[3][0]:
            return False
        inc0 = (points[0][1] - points[1][1]) / (points[0][0] - points[1][0])
        inc1 = (points[0][1] - points[2][1]) / (points[0][0] - points[2][0])
        inc2 = (points[1][1] - points[3][1]) / (points[1][0] - points[3][0])
        inc3 = (points[2][1] - points[3][1]) / (points[2][0] - points[3][0])
        
        if not math.isclose(inc0 * inc1, -1) or not math.isclose(inc0 * inc2, -1) or not math.isclose(inc1 * inc3, -1) or not math.isclose(inc2 * inc3, -1):
            return False
        return True