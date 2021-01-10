class SetOfStacks:
    def __init__(self, capacity):
        self.s1, self.s2, self.s3 = [], [], []
        self.capacity = capacity

    def push(self, val):
        if len(self.s1) < self.capacity:
            self.s1.append(val)
            return

        if len(self.s2) < self.capacity:
            self.s2.append(val)
            return

        if len(self.s3) < self.capacity:
            self.s3.append(val)
            return
        
        print("Error: The stack is full.")

    def pop(self):
        if len(self.s3) > 0:
            return self.s3.pop()

        if len(self.s2) > 0:
            return self.s2.pop()

        if len(self.s1) > 0:
            return self.s1.pop()
        
        return None
    
    def popAt(self, i):
        if i < 0:
            return None

        if i < self.capacity:
            return self.s1.pop(i)
        
        if i < 2 * self.capacity:
            return self.s2.pop(i % self.capacity)

        if i < 3 * self.capacity:
            return self.s3.pop(i % self.capacity)

        return None

if __name__ == '__main__':
    sos = SetOfStacks(3)
    sos.push(0)
    sos.push(1)
    sos.push(2)
    sos.push(3)
    sos.push(4)
    sos.push(5)
    sos.push(6)
    sos.push(7)
    sos.push(8)
    sos.push(9) # Error
    print(sos.popAt(2)) # 2
    print(sos.pop()) #8