from collections import defaultdict

# 59:51
class AccountNode:
    def __init__(self, name, addrList, next):
        self.name = name
        self.addrList = addrList
        self.next = next

class Solution:
    def accountsMerge(self, accounts):
        addrMap = dict()
        for account in accounts:
            accountNode = AccountNode(account[0], account[1:], [])
            for i in range(1, len(account)):
                if account[i] in addrMap:
                    self.mergeAccountNode(addrMap[account[i]], accountNode)
                else:
                    addrMap[account[i]] = accountNode
                    
        visited = set()
        res = []
        for account in accounts:
            accountNode = addrMap[account[1]]
            if accountNode not in visited:
                addrSet = set()
                self.depthFirstSearch(accountNode, visited, addrSet)
                newAccount = [account[0]]
                newAccount.extend(sorted(list(addrSet)))
                res.append(newAccount)
        return res
    
    def mergeAccountNode(self, account1, account2):
        account1.next.append(account2)
        account2.next.append(account1)
    
    def depthFirstSearch(self, accountNode, visited, addrSet):
        addrSet.update(set(accountNode.addrList))
        visited.add(accountNode)
        for nextNode in accountNode.next:
            if nextNode not in visited:
                self.depthFirstSearch(nextNode, visited, addrSet)


class DSU:
    def __init__(self):
        self.par = list(range(10001))
    
    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]
    
    def union(self, x, y):
        self.par[self.find(x)] = self.find(y)

class Solution2:
    def accountsMerge(self, accounts):
        em_to_name = dict()
        em_to_id = dict()
        index = 0
        dsu = DSU()
        for account in accounts:
            name = account[0]
            for email in account[1:]:
                em_to_name[email] = name
                if email not in em_to_id:
                    em_to_id[email] = index
                    index += 1
                dsu.union(em_to_id[account[1]], em_to_id[email])
                
        ans = defaultdict(list)
        for email in em_to_name:
            ans[dsu.find(em_to_id[email])].append(email)
        
        return [[em_to_name[v[0]]] + sorted(v) for v in ans.values()]