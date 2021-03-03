class Node:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

def find_loop(head):
    node1 = head.next
    node2 = head.next.next
    while node1 != node2:
        node1 = node1.next
        node2 = node2.next.next
    
    node1 = head
    while node1 != node2:
        node1 = node1.next
        node2 = node2.next
    return node1

def create_loop_list(nums, loop_ind, i=0, loop_node=None):
    if i >= len(nums):
        return loop_node
    
    node = Node(nums[i])
    if i == loop_ind:
        loop_node = node
    node.next = create_loop_list(nums, loop_ind, i + 1, loop_node)
    return node

if __name__ == '__main__':
    nums = [0, 1, 2, 3, 4, 5, 6]
    head = create_loop_list(nums, 2)
    res = find_loop(head)
    print(res.val)
