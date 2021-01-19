class Node(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def split_list(node, target):
    low_dummy = Node()
    low_cur = low_dummy
    high_dummy = Node()
    high_cur = high_dummy
    while node:
        if target > node.val:
            low_cur.next = node
            low_cur = low_cur.next
        else:
            high_cur.next = node
            high_cur = high_cur.next
        
        node = node.next

    low_cur.next = high_dummy.next
    high_cur.next = None
    return low_dummy.next

def split_list2(node, target):
    head = node
    tail = node
    node = node.next
    while node:
        nex = node.next
        if node.val < target:
            node.next = head
            head = node
        else:
            tail.next = node
            tail = node
        node = nex
    
    tail.next = None
    return head

def create_linked_list(nums, i):
    if i >= len(nums):
        return None
    node = Node(nums[i])
    node.next = create_linked_list(nums, i+1)
    return node

def output(node):
    if not node:
        return
    print(node.val)
    output(node.next)

if __name__ == '__main__':
    nums = [3, 5, 8, 5, 10, 2, 1]
    head = create_linked_list(nums, 0)
    head = split_list2(head, 5)
    output(head)