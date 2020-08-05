import random

def rand5():
    return random.randint(0, 4)

def rand7():
    while True:
        num = 5 * rand5() + rand5()
        if num < 21:
            return num % 7

if __name__ == '__main__':
    print(rand7())