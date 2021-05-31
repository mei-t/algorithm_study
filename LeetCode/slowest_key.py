class Solution:
    def slowestKey(self, releaseTimes, keysPressed):
        res = ''
        max_dur = -1
        prev = 0
        for i in range(len(releaseTimes)):
            dur = releaseTimes[i] - prev
            if dur > max_dur or (dur == max_dur and ord(res) < ord(keysPressed[i])):
                max_dur = dur
                res = keysPressed[i]
            prev = releaseTimes[i]
        
        return res