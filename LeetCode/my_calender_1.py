class MyCalendar:

    def __init__(self):
        self.calender = []
        

    def book(self, start, end):
        for schedule in self.calender:
            if schedule[0] < end and start < schedule[1]:
                return False
        
        self.calender.append((start, end))
        return True