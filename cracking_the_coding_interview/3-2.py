class StackNode:
    def __init__(self, val, min_val):
        self.val = val
        self.min_val = min_val

class MinStack:
    def __init__(self):
        self.stack = []
    
    def push(self, val):
        if len(self.stack) > 0:
            min_val = self.stack[-1].min_val
        else:
            min_val = val

        if min_val > val:
            min_val = val
        
        self.stack.append(StackNode(val, min_val))

    def pop(self):
        return self.stack.pop().val
    
    def min(self):
        return self.stack[-1].min_val


if __name__ == '__main__':
    ms = MinStack()
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
