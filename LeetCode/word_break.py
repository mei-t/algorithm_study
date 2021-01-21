from collections import defaultdict

class Solution(object):
    def wordBreak(self, s, wordDict):
        word_map = defaultdict(list)
        wordDict.sort(reverse=True)
        for word in wordDict:
            if word[0] not in word_map:
                word_map[word[0]] = []
            word_map[word[0]].append(word)
        return self.segmentWord(s, word_map, dict())
    
    def segmentWord(self, s, word_map, s_map):
        if len(s) == 0:
            return True
        
        if s in s_map:
            return s_map[s]

        for word in word_map[s[0]]:
            if word == s[:len(word)]:
                res = self.segmentWord(s[len(word):], word_map, s_map)
                if res:
                    s_map[s] = True
                    break
        
        if s not in s_map:
            s_map[s] = False

        return s_map[s]


if __name__ == "__main__":
    # wordDict = ["leet", "code"]
    # wordDict = ["apple", "pen"]
    wordDict = ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
    sol = Solution()
    res = sol.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict)
    # res = sol.wordBreak("applepenapple", wordDict)
    # res = sol.wordBreak("leetcode", wordDict)
    print(res)