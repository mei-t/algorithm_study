import heapq
import sys

class Box:
    def __init__(self, h, w, d):
        self.h = h
        self.w = w
        self.d = d


def findHighest(boxes):
    h = []
    for box in boxes:
        heapq.heappush(h, (-box.h, -box.w, -box.d))

    heights = [[0, (sys.maxsize, sys.maxsize, sys.maxsize)]]
    while len(h):
        box = heapq.heappop(h)
        for height in heights:
            if -box[0] < height[1][0] and -box[1] < height[1][1] and -box[2] < height[1][2]:
                heights.append([height[0] - box[0], (-box[0], -box[1], -box[2])])
        
    ans = 0
    for height in heights:
        if ans < height[0]:
            ans = height[0]
    return ans



if __name__ == '__main__':
    boxes = []
    boxes.append(Box(1, 1, 2))
    boxes.append(Box(3, 1, 2))
    boxes.append(Box(2, 2, 3))
    boxes.append(Box(3, 3, 3))
    print(findHighest(boxes))