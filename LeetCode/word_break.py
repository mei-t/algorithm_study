from collections import defaultdict

class Solution1(object):
    def wordBreak(self, s, wordDict):
        wordMap = defaultdict(list)
        wordDict.sort(reverse=True)
        for word in wordDict:
            if word[0] not in wordMap:
                wordMap[word[0]] = []
            wordMap[word[0]].append(word)
        return self.segmentWord(s, wordMap, dict())
    
    def segmentWord(self, s, wordMap, sMap):
        if len(s) == 0:
            return True
        
        if s in sMap:
            return sMap[s]

        for word in wordMap[s[0]]:
            if word == s[:len(word)]:
                res = self.segmentWord(s[len(word):], wordMap, sMap)
                if res:
                    sMap[s] = True
                    break
        
        if s not in sMap:
            sMap[s] = False

        return sMap[s]

class Solution(object):
    def wordBreak(self, s, wordDict):
        return self.segmentWord(s, wordDict, dict())
    
    def segmentWord(self, s, wordDict, sDict):
        if len(s) == 0:
            return True
        
        if s in sDict:
            return sDict[s]
        
        for word in wordDict:
            if word == s[:len(word)]:
                res = self.segmentWord(s[len(word):], wordDict, sDict)
                if res:
                    sDict[s] = True
                    break
        
        if s not in sDict:
            sDict[s] = False

        return sDict[s]

if __name__ == "__main__":
    # wordDict = ["leet", "code"]
    # wordDict = ["apple", "pen"]
    wordDict = ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
    sol = Solution()
    res = sol.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict)
    # res = sol.wordBreak("applepenapple", wordDict)
    # res = sol.wordBreak("leetcode", wordDict)
    print(res)