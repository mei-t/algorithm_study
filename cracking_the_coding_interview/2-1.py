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
    num_set = {}
    while node:
        if node.val in num_set:
            ll.delete(node.val)
        num_set.append(node.val)

