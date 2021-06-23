from collections import defaultdict

class Solution:
    def mostVisitedPattern(self, username, timestamp, website):
        user_map = defaultdict(list)
        for i in range(len(username)):
            user_map[username[i]].append([timestamp[i], website[i]])
        
        seq_map = defaultdict(int)
        for user in user_map:
            visited = set()
            l = user_map[user]
            l.sort()
            for i in range(len(l) - 2):
                for j in range(i + 1, len(l) - 1):
                    for k in range(j + 1, len(l)):
                        tmp = (l[i][1], l[j][1], l[k][1])
                        if tmp in visited:
                            continue
                        seq_map[tmp] += 1
                        visited.add(tmp)
        
        max_count = 0
        res = []
        for seq in seq_map:
            if seq_map[seq] < max_count:
                continue
            if seq_map[seq] == max_count and res < list(seq):
                continue
            res = list(seq)
            max_count = seq_map[seq]
                        
        return res
        