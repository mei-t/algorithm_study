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

class Solution2:
    def mergeTwoLists(self, l1, l2):
        prehead = ListNode()
        prev = prehead
        while l1 or l2:
            if not l1:
                prev.next = l2
                l2 = None
            elif not l2:
                prev.next = l1
                l1 = None
            elif l1.val <= l2.val:
                prev.next = l1
                l1 = l1.next
            else:
                prev.next = l2
                l2 = l2.next
            prev = prev.next
        return prehead.next

# TC: O(m + n)
# SC: O(m + n)
class Solution3:
    def mergeTwoLists(self, l1, l2):
        if not l2:
            return l1
        if not l1:
            return l2
        if l1.val <= l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        l2.next = self.mergeTwoLists(l1, l2.next)
        return l2
        