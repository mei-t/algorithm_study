class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def is_palindrome(root):
    res = []
    search_node(root, res)
    for i in range(len(res) // 2):
        if res[i] != res[len(res) - i - 1]:
            return False
    
    return True

def search_node(node, res):
    if not node:
        return
    res.append(node.val)
    search_node(node.next, res)

def create_linked_list(nums, i=0):
    if i >= len(nums):
        return None
    node = ListNode(nums[i])
    node.next = create_linked_list(nums, i + 1)
    return node

if __name__ == '__main__':
    nums = [0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0]
    root = create_linked_list(nums, 0)
    res = is_palindrome(root)
    print(res)