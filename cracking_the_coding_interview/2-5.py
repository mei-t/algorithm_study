import unittest

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def add_list(node1, node2):
    return compute(node1, node2, 0)

def compute(node1, node2, carry):
    if not node1 and not node2:
        return None
    
    v1 = 0
    v2 = 0
    if node1:
        v1 = node1.val
        node1 = node1.next
    if node2:
        v2 = node2.val
        node2 = node2.next
    
    ans = v1 + v2 + carry
    carry = ans // 10
    ans %= 10
    node = ListNode(ans)
    node.next = compute(node1, node2, carry)
    return node

# 発展問題
def add_list_reversed(node1, node2):
    return compute_sum(node1, node2)[0]

def compute_sum(node1, node2):
    if not node1 and not node2:
        return None, 0
    
    v1, v2 = 0, 0
    if node1:
        v1 = node1.val
        node1 = node1.next
    if node2:
        v2 = node2.val
        node2 = node2.next

    next_res = compute_sum(node1, node2)
    ans = v1 + v2 + next_res[1]
    carry = ans // 10
    ans %= 10
    node = ListNode(ans)
    node.next = next_res[0]
    return node, carry

def create_linked_list(nums, i):
    if i >= len(nums):
        return None
    node = ListNode(nums[i])
    node.next = create_linked_list(nums, i+1)
    return node

def output(node):
    if not node:
        return
    
    print(node.val)
    output(node.next)

class Test(unittest.TestCase):
    def test_simple(self):
        nums1 = [7, 1, 6]
        nums2 = [5, 9, 2]
        expected = [2, 1, 9]
        head1 = create_linked_list(nums1, 0)
        head2 = create_linked_list(nums2, 0)
        res = add_list(head1, head2)
        for e in expected:
            self.assertEqual(res.val, e)
            res = res.next
        self.assertEqual(res, None)


if __name__ == '__main__':
    # unittest.main()
    nums1 = [6, 1, 7]
    nums2 = [2, 9, 5]
    node1 = create_linked_list(nums1, 0)
    node2 = create_linked_list(nums2, 0)
    res = add_list_reversed(node1, node2)
    output(res)