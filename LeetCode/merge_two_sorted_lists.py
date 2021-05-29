class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1, l2):
        if not l1 and not l2:
            return l1
        if not l1:
            merged = l2
            l2 = l2.next
        elif not l2:
            merged = l1
            l1 = l1.next
        else:
            if l1.val <= l2.val:
                merged = l1
                l1 = l1.next
            else:
                merged = l2
                l2 = l2.next
        head = merged
        while l1 and l2:
            if l1.val <= l2.val:
                merged.next = l1
                l1 = l1.next
            else:
                merged.next = l2
                l2 = l2.next
            merged = merged.next
        if l1:
            merged.next = l1
        if l2:
            merged.next = l2
        return head
        