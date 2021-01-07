class Node:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

def deleteNode(node):
    del_node = node.next
    node.val = node.next.val
    node.next = node.next.next
    del del_node
    return

def createLinkedList(nums, i):
    if i >= len(nums):
        return None
    
    node = Node(nums[i])
    node.next = createLinkedList(nums, i + 1)
    return node

def output(node):
    while node:
        print(node.val)
        node = node.next

if __name__ == '__main__':
    nums = [0, 1, 2, 3, 4, 5]
    root = createLinkedList(nums, 0)
    deleteNode(root.next.next)
    output(root)