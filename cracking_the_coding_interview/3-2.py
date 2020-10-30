class StackNode:
    def __init__(self, val, min_val):
        self.val = val
        self.min_val = min_val

class MinStack:
    def __init__(self):
        self.stack = []
    
    def push(self, val):
        if self.stack:
            min_val = self.stack[-1].min_val
        else:
            min_val = val

        if min_val > val:
            min_val = val
        
        self.stack.append(StackNode(val, min_val))

    def pop(self):
        if not self.stack:
            return None
        return self.stack.pop().val
    
    def min(self):
        if not self.stack:
            return None
        return self.stack[-1].min_val


if __name__ == '__main__':
    ms = MinStack()
    print(ms.min())
    print(ms.pop())
    ms.push(3)
    ms.push(1)
    ms.push(5)
    print(ms.min())
    ms.push(0)
    ms.push(2)
    print(ms.min())
    print(ms.pop())
    print(ms.pop())
    print(ms.min())
