class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class NodeData(object):
    def __init__(self, even=None, odd=None, even_last=None):
        self.even = even
        self.odd = odd
        self.even_last = even_last

class SolutionWithRec(object):
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

class SolutionWithForRoop(object):
    def oddEvenList(self, head):
        if head == None:
            return head
        even = head
        odd = head.next
        odd_head = odd
        while(odd != None and odd.next != None):
            even.next = odd.next
            odd.next = odd.next.next
            even = even.next
            odd = odd.next
        even.next = odd_head
        return head
        

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
    head_rec1 = createLikedList(nums1)
    head_for1 = createLikedList(nums1)
    head_rec2 = createLikedList(nums2)
    head_for2 = createLikedList(nums2)

    print("Solution with recursion")
    sol_rec = SolutionWithRec()

    node_rec1 = sol_rec.oddEvenList(head_rec1)
    while node_rec1 != None:
        print(node_rec1.val)
        node_rec1 = node_rec1.next

    node_rec2 = sol_rec.oddEvenList(head_rec2)
    while node_rec2 != None:
        print(node_rec2.val)
        node_rec2 = node_rec2.next

    print("Solution with for roop")
    sol_for = SolutionWithForRoop()

    node_for1 = sol_for.oddEvenList(head_for1)
    while node_for1 != None:
        print(node_for1.val)
        node_for1 = node_for1.next

    node_for2 = sol_for.oddEvenList(head_for2)
    while node_for2 != None:
        print(node_for2.val)
        node_for2 = node_for2.next