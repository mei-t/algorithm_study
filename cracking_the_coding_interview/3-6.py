from enum import Enum
import time

class Animal(Enum):
    DOG = 0
    CAT = 1

class ListNode(object):
    def __init__(self, name, breed, time, next=None):
        self.name = name
        self.breed = breed
        self.time = time
        self.next = next

class AnimalShelter(object):
    def __init__(self):
        self.dog_head = ListNode("", Animal.DOG, 0)
        self.cat_head = ListNode("", Animal.CAT, 0)
        self.dog_last = self.dog_head
        self.cat_last = self.cat_head
    
    def enqueue(self, name, breed):
        t = time.time()
        node = ListNode(name, breed, t)
        if breed == Animal.DOG:
            self.dog_last.next = node
            self.dog_last = node
        else:
            self.cat_last.next = node
            self.cat_last = node
    
    def dequeue_any(self):
        if not self.dog_head.next:
            return self.dequeue_cat()
        if not self.cat_head.next:
            return self.dequeue_dog()
        
        dog_t = self.dog_head.next.time
        cat_t = self.cat_head.next.time
        return self.dequeue_dog() if dog_t < cat_t else self.dequeue_cat()
    
    def dequeue_dog(self):
        if not self.dog_head.next:
            return None
        node = self.dog_head.next
        self.dog_head.next = self.dog_head.next.next
        return node
    
    def dequeue_cat(self):
        if not self.cat_head.next:
            return None
        node = self.cat_head.next
        self.cat_head.next = self.cat_head.next.next
        return node

if __name__ == '__main__':
    al = AnimalShelter()
    al.enqueue("Pochi", Animal.DOG)
    al.enqueue("Mike", Animal.CAT)
    al.enqueue("Shiro", Animal.DOG)
    al.enqueue("Kotetsu", Animal.DOG)
    al.enqueue("Tama", Animal.CAT)
    print(al.dequeue_dog().name)
    print(al.dequeue_any().name)
    print(al.dequeue_cat().name)
    print(al.dequeue_cat().name)
    print(al.dequeue_any().name)

