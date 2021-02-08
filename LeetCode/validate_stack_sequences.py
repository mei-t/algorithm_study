# 13:15

class Solution(object):
    def validateStackSequences(self, pushed, popped):
        s = []
        pop_i = 0
        while pop_i < len(popped):
            while not s or s[-1] != popped[pop_i]:
                if not pushed:
                    return False
                s.append(pushed.pop(0))
            while s and s[-1] == popped[pop_i]:
                s.pop()
                pop_i += 1
            
        return True

class Solution2(object):
    def validateStackSequences(self, pushed, popped):
        s = []
        push_i = 0
        pop_i = 0
        while pop_i < len(popped):
            while not s or s[-1] != popped[pop_i]:
                if push_i >= len(pushed):
                    return False
                s.append(pushed[push_i])
                push_i += 1
            while s and s[-1] == popped[pop_i]:
                s.pop()
                pop_i += 1
            
        return True