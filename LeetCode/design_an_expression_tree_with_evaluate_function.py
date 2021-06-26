import abc 
from abc import ABC, abstractmethod 

# デザイン的にいいコードではないかも

class TreeNode(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def strToNum(st):
    idx = 0
    res = 0
    while idx < len(st):
        tmp = st[idx]
        res *= 10
        res += ord(tmp) - ord('0')
        idx += 1
    return res
        
class Node(ABC):
    def __init__(self, root):
        self.root = root
    
    @abstractmethod
    # define your fields here
    def evaluate(self):
        pass

class ImplementNode(Node):
    def evaluate(self):
        def calculate(tree_node):
            if not tree_node.left:
                return strToNum(tree_node.val)
            
            l = calculate(tree_node.left)
            r = calculate(tree_node.right)
            if tree_node.val == '+':
                return l + r
            if tree_node.val == '-':
                return l - r
            if tree_node.val == '*':
                return l * r
            return l // r
        
        return calculate(self.root)



class TreeBuilder(object):
    def buildTree(self, postfix):
        def createTree(s, postfix, idx):
            if idx == len(postfix):
                return s.pop()
            
            operators = ['+', '-', '*', '/']
            l = r = None
            if postfix[idx] in operators:
                r = s.pop()
                l = s.pop()
            
            tree_node = TreeNode(postfix[idx], l, r)
            s.append(tree_node)
            return createTree(s, postfix, idx + 1)
        
        return ImplementNode(createTree([], postfix, 0))
        
		

        