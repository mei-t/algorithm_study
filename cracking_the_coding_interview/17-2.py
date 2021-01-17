import random
from enum import Enum

class Mark(Enum):
	SPADE = 1
	HEART = 2
	DIAMOND = 3
	CLUB= 4

class Card(object):
	def __init__(self, mark, number):
		self.mark = mark
		self.number = number

class Deck(object):
	def __init__(self):
		self.deck = []
		self.size = 0

	def draw(self):
		self.size -= 1
		return self.deck.pop(0)
	
	def put(self, card):
		self.deck.append(card)
		self.size += 1
		return
	
	def shuffle(self):
		for i in range(1, self.size):
			j = random.randrange(i)
			self.deck[i], self.deck[j] = self.deck[j], self.deck[i]
		return

def output(d):
    for i in range(d.size):
        card = d.deck[i]
        print(card.mark, card.number)

if __name__ == '__main__':
    d = Deck()
    for i in range(0, 5):
        for j in range(0, 14):
            card = Card(i, j)
            d.put(card)
    output(d)
    d.shuffle()
    print("-----------shuffle-------------")
    output(d)