class MyQueue(object):
    def __init__(self):
        self.s1 = []
        self.s2 = []

    def put(self, val):
        while len(self.s2) > 0:
            self.s1.append(self.s2.pop())
        self.s1.append(val)
        return
    
    def get(self):
        if not self.s1 and not self.s2:
            return None
        while len(self.s1) > 1:
            self.s2.append(self.s1.pop())
        return self.s1.pop() if len(self.s1) > 0 else self.s2.pop()

if __name__ == "__main__":
    q = MyQueue()
    q.put(0)
    q.put(1)
    q.put(2)
    print(q.get()) # 0
    q.put(3)
    print(q.get()) # 1
    print(q.get()) # 2
    print(q.get()) # 3
    print(q.get()) # None
    q.put(4)
    print(q.get()) # 4