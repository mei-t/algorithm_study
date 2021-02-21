import unittest

class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def common_node(node1, node2):
    tmp1 = node1
    count1 = 0
    while tmp1.next:
        tmp1 = tmp1.next
        count1 += 1

    tmp2 = node2
    count2 = 0
    while tmp2.next:
        tmp2 = tmp2.next
        count2 += 1
    
    if tmp1 != tmp2:
        return None
    
    if count1 > count2:
        for _ in range(count1 - count2):
            node1 = node1.next
    else:
        for _ in range(count2 - count1):
            node2 = node2.next
    
    while node1 != node2:
        node1 = node1.next
        node2 = node2.next
    
    return node1

def create_node(nums, i):
    if i >= len(nums):
        return None

    node = Node(nums[i])
    node.next = create_node(nums, i + 1)
    return node

def connect(node1, pos, node2):
    for _ in range(pos):
        node1 = node1.next

    while node2.next:
        node2 = node2.next
    
    node2.next = node1

class Test(unittest.TestCase):
    def test_no_common(self):
        nums1 = [3, 6, 7, 39, 2, 1, 0, 5, 24]
        nums2 = [0, 4, 1, 5, 8, 2]
        node1 = create_node(nums1, 0)
        node2 = create_node(nums2, 0)
        res = common_node(node1, node2)
        self.assertEquals(res, None)
    
    def test_common(self):
        nums1 = [3, 6, 7, 39, 2, 1, 0, 5, 24]
        nums2 = [0, 4, 1, 5, 8, 2]
        node1 = create_node(nums1, 0)
        node2 = create_node(nums2, 0)
        connect(node1, 5, node2)
        res = common_node(node1, node2)
        self.assertEquals(res.val, 1)

if __name__ == '__main__':
    unittest.main()