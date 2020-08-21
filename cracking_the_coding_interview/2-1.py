import unittest

class ListNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, val):
        node = ListNode(val)
        if not self.head:
            self.head = node
            return
        
        cur = self.head
        while cur.next:
            cur = cur.next
        cur.next = node


    def find(self, val):
        node = self.head
        while node:
            if node.val == val:
                return node
            node = node.next
        return None
    
    def delete(self, val):
        node = self.head
        if val == node.val:
            del_node = node
            self.head = node.next
            del del_node
            return

        while node.next:
            if node.next.val == val:
                del_node = node.next
                node.next = node.next.next
                del del_node
                return
            node = node.next
        return


def delete_dupli_with_buffer(ll):
    node = ll.head
    num_set = set()
    while node:
        if node.val in num_set:
            ll.delete(node.val)
        num_set.add(node.val)
        node = node.next

    
def delete_dupli_without_buffer(ll):
    node = ll.head
    while node:
        next_node = node.next
        while next_node:
            if node.val == next_node.val:
                ll.delete(node.val)

            next_node = next_node.next

        node = node.next

class Test(unittest.TestCase):
    def test_with_buffer(self):
        nums = [0, 1, 2, 1, 3, 3]
        expected = [0, 2, 1, 3]
        ll = LinkedList()
        for num in nums:
            ll.append(num)
        
        delete_dupli_with_buffer(ll)
        node = ll.head
        for e in expected:
            self.assertEqual(e, node.val)
            node = node.next
    
    def test_without_buffer(self):
        nums = [0, 1, 2, 1, 3, 3]
        expected = [0, 2, 1, 3]
        ll = LinkedList()
        for num in nums:
            ll.append(num)
        
        delete_dupli_without_buffer(ll)
        node = ll.head
        for e in expected:
            self.assertEqual(e, node.val)
            node = node.next


if __name__ == '__main__':
    unittest.main()
    

