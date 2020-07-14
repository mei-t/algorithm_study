class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class NodeData(object):
    def __init__(self, even=None, odd=None, even_last=None):
        self.even = even
        self.odd = odd
        self.even_last = even_last

class Solution(object):
    def oddEvenList(self, head):
        if head == None or head.next == None or head.next.next == None:
            return head
        odd_head = head.next
        next_nodes = self.oddEvenNext(odd_head.next)
        head.next = next_nodes.even
        odd_head.next = next_nodes.odd
        next_nodes.even_last.next = odd_head
        return head


    def oddEvenNext(self, even):
        odd = even.next
        if odd == None or odd.next == None:
            return NodeData(even, odd, even)

        next_nodes = self.oddEvenNext(odd.next)
        even.next = next_nodes.even
        odd.next = next_nodes.odd
        return NodeData(even, odd, next_nodes.even_last)

def createLinkedNode(nums, node, index):
    if len(nums) == index:
        return None
    node = ListNode(nums[index])
    node.next = createLinkedNode(nums, node, index + 1)
    return node

def createLikedList(nums):
    if len(nums) == 0:
        return None
    head = ListNode(nums[0])
    head.next = createLinkedNode(nums, head, 1)
    return head

if __name__ == '__main__':
    nums1 = [1,2,3,4,5]
    nums2 = [1, 1]
    head1 = createLikedList(nums1)
    head2 = createLikedList(nums2)
    sol = Solution()
    node1 = sol.oddEvenList(head1)
    
    while node1 != None:
        print(node1.val)
        node1 = node1.next

    node2 = sol.oddEvenList(head2)
    while node2 != None:
        print(node2.val)
        node2 = node2.next
