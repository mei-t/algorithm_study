import unittest

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def removeNthFromEnd(self, head, n):
        if not head or not head.next:
            return None
        tmp = head
        target = head
        while n > 0:
            tmp = tmp.next
            n -= 1
        
        while tmp and tmp.next:
            tmp = tmp.next
            target = target.next
        
        if tmp:
            del_node = target.next
            target.next = target.next.next
        else:
            del_node = head
            head = head.next
        del del_node
        return head

def createLinkedList(nums, i):
    if i >= len(nums):
        return None
    
    node = ListNode(nums[i])
    node.next = createLinkedList(nums, i + 1)
    return node

class Test(unittest.TestCase):
    def prepare(self, nums, n):
        head = createLinkedList(nums, 0)
        sol = Solution()
        return sol.removeNthFromEnd(head, n)

    def test_simple(self):
        nums = [1, 2, 3, 4, 5]
        expected = [1, 2, 3, 5]
        res = self.prepare(nums, 2)
        for num in expected:
            self.assertEqual(num, res.val)
            res = res.next
    
    def test_short1(self):
        nums = [1, 2]
        expected = [2]
        res = self.prepare(nums, 2)
        for num in expected:
            self.assertEqual(num, res.val)
            res = res.next
    
    def test_short2(self):
        nums = [1, 2]
        expected = [1]
        res = self.prepare(nums, 1)
        for num in expected:
            self.assertEqual(num, res.val)
            res = res.next

if __name__ == '__main__':
    unittest.main()
