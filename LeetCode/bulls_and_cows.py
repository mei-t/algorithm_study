import collections

class Solution:
    def getHint(self, secret, guess):
        secret_map = collections.Counter(secret)
        guess_map = collections.Counter(guess)
        bulls = 0
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
                c = secret[i]
                secret_map[c] -= 1
                guess_map[c] -= 1
        
        cows = 0
        for c in secret_map:
            if c not in guess_map:
                continue
            cows += min(secret_map[c], guess_map[c])
        return "{}A{}B".format(bulls, cows)

# 17:52
class Solution1:
    def getHint(self, secret, guess):
        bulls = 0
        cows = 0
        secret_map = dict()
        guess_map = dict()
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                if secret[i] in guess_map:
                    cows += 1
                    guess_map[secret[i]] -= 1
                    if guess_map[secret[i]] == 0:
                        del guess_map[secret[i]]
                else:
                    if secret[i] not in secret_map:
                        secret_map[secret[i]] = 0
                    secret_map[secret[i]] += 1
                    
                if guess[i] in secret_map:
                    cows += 1
                    secret_map[guess[i]] -= 1
                    if secret_map[guess[i]] == 0:
                        del secret_map[guess[i]]
                else:
                    if guess[i] not in guess_map:
                        guess_map[guess[i]] = 0
                    guess_map[guess[i]] += 1
        
        return "{}A{}B".format(bulls, cows)