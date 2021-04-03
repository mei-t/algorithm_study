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