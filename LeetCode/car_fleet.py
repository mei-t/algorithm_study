# 30:55
class Solution:
    def carFleet(self, target, position, speed):
        if not position:
            return 0
        position = [target - position[i] for i in range(len(position))]
        cars = sorted(zip(position, speed))
        
        count = 1
        head_time = cars[0][0] / cars[0][1]
        cur_i = 1
        while cur_i < len(cars):
            cur_time = cars[cur_i][0] / cars[cur_i][1]
            if head_time < cur_time:
                head_time = cur_time
                count += 1
            cur_i += 1
        return count