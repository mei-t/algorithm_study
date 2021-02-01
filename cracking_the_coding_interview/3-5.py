from copy import deepcopy

class Stack(object):
    def __init__(self, s):
        self.s = s
    
    def push(self, val):
        self.s.append(val)
    
    def pop(self):
        assert self.is_empty() == False, "Stack is empty()"
        return self.s.pop()
    
    def peek(self):
        assert self.is_empty() == False, "Stack is empty()"
        return self.s[-1]
    
    def is_empty(self):
        return len(self.s) == 0
    
    def check(self):
        return self.s

def sort_stack(s):
    if s.is_empty():
        return
    
    sorted_s = Stack([])
    temp_s = Stack([])
    sorted_s.push(s.pop())

    while not s.is_empty():
        cur = s.pop()
        while not sorted_s.is_empty() and sorted_s.peek() > cur:
            val = sorted_s.pop()
            temp_s.push(val)
        sorted_s.push(cur)
        while not temp_s.is_empty():
            sorted_s.push(temp_s.pop())
        
    while not sorted_s.is_empty():
        s.push(sorted_s.pop())

def sort_stack_with_two_stack(s1):
    s2 = []
    while s1:
        tmp = s1.pop()
        count = 0
        while s2 and s2[-1] > tmp:
            s1.append(s2.pop())
            count += 1
        
        s2.append(tmp)
        
        while count > 0:
            s2.append(s1.pop())
            count -= 1
        
    while s2:
        s1.append(s2.pop())

if __name__ == '__main__':
    nums = [0]
    s = [4, 45, 6, 72, 0, 25]
    # sort_stack_with_two_stack(s)
    # print(s)
    stack = Stack(s)
    sort_stack(stack)
    while not stack.is_empty():
        print(stack.pop())