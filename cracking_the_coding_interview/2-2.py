class ListNode:
    def __init__(self, val, next_node):
        self.val = val
        self.next = next_node

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, val):
        node = ListNode(val, None)
        if self.head == None:
            self.head = node
            return
        
        cur_node = self.head
        while cur_node.next != None:
            cur_node = cur_node.next
        cur_node.next = node

def findKthFromEnd(root, k):
    node = root
    count = 0
    while node != None:
        node = node.next
        count += 1

    node = root
    count -= k
    while count > 0:
        node = node.next
        count -= 1

    return node

if __name__ == '__main__':
    ll = LinkedList()
    for i in range(5):
        ll.append(i)
    res = findKthFromEnd(ll.head, 2)
    print(res.val)

