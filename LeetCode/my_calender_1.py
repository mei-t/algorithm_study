class TreeNode:
    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.left = None
        self.right = None
    
    def insert(self, node):
        if node.start >= self.end:
            if not self.right:
                self.right = node
                return True
            return self.right.insert(node)
        if node.end <= self.start:
            if not self.left:
                self.left = node
                return True
            return self.left.insert(node)
        return False

class MyCalendar:

    def __init__(self):
        self.root = None

    def book(self, start, end):
        node = TreeNode(start, end)
        if not self.root:
            self.root = node
            return True
        return self.root.insert(node)

class MyCalendar2:

    def __init__(self):
        self.calender = []
    
    def binary_search(self, left, right, start, end):
        mid = (left + right) // 2
        if left >= right or mid >= len(self.calender):
            return True
        
        mid_start = self.calender[mid][0]
        mid_end = self.calender[mid][1]
        if mid_start < end and start < mid_end:
            return False
        if end <= mid_start:
            return self.binary_search(left, mid, start, end)
        else:
            return self.binary_search(mid + 1, right, start, end)

    def book(self, start, end):
        if self.calender and not self.binary_search(0, len(self.calender), start, end):
            return False
        
        self.calender.append((start, end))
        self.calender.sort()
        return True

# 15:03
class MyCalendar1:

    def __init__(self):
        self.calender = []
        

    def book(self, start, end):
        for schedule in self.calender:
            if schedule[0] < end and start < schedule[1]:
                return False
        
        self.calender.append((start, end))
        return True