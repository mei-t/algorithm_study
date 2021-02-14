class SnapNode:
    def __init__(self, val, snap_id=-1, prev=None):
        self.val = val
        self.snap_id = snap_id
        self.prev = prev
    
class SnapshotArray(object):

    def __init__(self, length):
        self.array = [SnapNode(0) for _ in range(length)]
        self.snap_count = 0

    def set(self, index, val):
        if self.array[index].snap_id == -1:
            self.array[index].val = val
        else:
            prev_node = self.array[index]
            prev_id = prev_node.snap_id
            node = SnapNode(val, -1, prev_node)
            self.array[index] = node

    def snap(self):
        for node in self.array:
            if node.snap_id == -1:
                node.snap_id = self.snap_count
        self.snap_count += 1
        return self.snap_count - 1
        
    def get(self, index, snap_id):
        node = self.array[index]
        while node.snap_id == -1 or snap_id < node.snap_id:
            node = node.prev
        return node.val

if __name__ == '__main__':
    ssa = SnapshotArray(1)
    ssa.snap()
    ssa.snap()
    ssa.set(0, 4)
    ssa.snap()
    print(ssa.get(0, 1))
    ssa.set(0, 12)
    print(ssa.get(0, 1))
    ssa.snap()
    print(ssa.get(0, 3))