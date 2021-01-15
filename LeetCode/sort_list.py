class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def sortList(self, head):
        tmp = head
        l = 0
        while tmp:
            l += 1
            tmp = tmp.next
        
        return self.mergeSort(head, l)
    
    def mergeSort(self, node, l):
        if l < 2:
            return node

        if l == 2:
            if node.val > node.next.val:
                tmp = node.next
                tmp.next = node
                node.next = None
                node = tmp
            return node
        
        tmp = node
        mid = l // 2 - 1
        while mid:
            mid -= 1
            tmp = tmp.next
        
        mid_node = tmp.next
        tmp.next = None
        left = self.mergeSort(node, l // 2)
        right = self.mergeSort(mid_node, l // 2 + l % 2)

        dummy = ListNode()
        node = dummy
        while left or right:
            if not right:
                node.next = left
                left = left.next
            elif not left:
                node.next = right
                right = right.next
            elif left.val < right.val:
                node.next = left
                left = left.next
            else:
                node.next = right
                right = right.next
            node = node.next

        return dummy.next

def createListNode(nums, i):
    if i >= len(nums):
        return None
    node = ListNode(nums[i])
    node.next = createListNode(nums, i + 1)
    return node

def output(node):
    while node:
        print(node.val)
        node = node.next
    print("-------")

if __name__ == '__main__':
    # nums = [4, 2, 1, 3]
    nums = [-1, 5, 3, 4, 0]
    head = createListNode(nums, 0)
    sol = Solution()
    node = sol.sortList(head)
    output(node)