class MyCalendar:

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