# 51:57
class Solution1(object):
    def canTransform(self, start, end):
        if len(start) != len(end):
            return False
        i = 0
        while i < len(start):
            if start[i] == end[i]:
                i += 1
                continue
            if start[i] == 'X' and end[i] == 'L':
                start_l = 0
                end_l = 1
                i += 1
                while start_l != end_l:
                    if i >= len(start) or start[i] == 'R' or end[i] == 'R':
                        return False
                    if start[i] == 'L':
                        start_l += 1
                    if end[i] == 'L':
                        end_l += 1
                    i += 1
            elif start[i] =='R' and end[i] == 'X':
                start_r = 1
                end_r = 0
                i += 1
                while start_r != end_r:
                    if i >= len(start) or start[i] == 'L' or end[i] == 'L':
                        return False
                    if start[i] == 'R':
                        start_r += 1
                    if end[i] == 'R':
                        end_r += 1
                    i += 1
            else:
                return False
        
        return True

class Solution2(object):
    def canTransform(self, start, end):
        if start.replace("X", "") != end.replace("X", ""):
            return False
        
        l_pos = (i for i, e in enumerate(start) if e == 'L')
        for i, e in enumerate(end):
            if e == 'L' and i > next(l_pos):
                return False
            
        r_pos = (i for i, e in enumerate(start) if e == 'R')
        for i, e in enumerate(end):
            if e == 'R' and i < next(r_pos):
                return False
        return True
        