# 25:49
class Solution:
    def reconstructQueue(self, people):
        people.sort(key=lambda x:(-x[0],x[1]))
        # people.sort(key=lambda x:x[1])
        # people.sort(reverse=True, key=lambda x:x[0])
        res = []
        for person in people:
            res.insert(person[1], person)
        return res