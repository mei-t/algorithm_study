class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:
    none = 1001

    def serialize(self, root):
        def create_list_from_tree(node):
            if not node:
                res.append(self.none)
                return

            res.append(node.val)
            create_list_from_tree(node.left)
            create_list_from_tree(node.right)
        
        res = []
        create_list_from_tree(root)
        return ",".join(map(str, res))

    def deserialize(self, data):
        def create_tree_from_list(nums):
            val = nums.pop(0)
            if val == self.none:
                return None
            node = TreeNode(val)
            node.left = create_tree_from_list(nums)
            node.right = create_tree_from_list(nums)
            return node
        nums = [int(x) for x in data.split(",")]
        return create_tree_from_list(nums)

def output(node):
    if not node:
        print("None")
        return
    
    print(node.val)
    output(node.left)
    output(node.right)

if __name__ == '__main__':
    node1 = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)
    node4 = TreeNode(4)
    node5 = TreeNode(5)
    node1.left = node2
    node1.right = node3
    node3.left = node4
    node3.right = node5
    root = node1

    ser = Codec()
    deser = Codec()
    ans = deser.deserialize(ser.serialize(root))
    output(ans)