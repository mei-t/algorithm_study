class Solution1:
    def intToRoman(self, num):
        res = []
        if num // 1000:
            for _ in range(num // 1000):
                res.append('M')
            num %= 1000
        if num // 900:
            res.append('CM')
            num -= 900
        if num // 500:
            res.append('D')
            num -= 500
        if num // 400:
            res.append('CD')
            num -= 400
        if num // 100:
            for _ in range(num // 100):
                res.append('C')
            num %= 100
        if num // 90:
            res.append('XC')
            num -= 90
        if num // 50:
            res.append('L')
            num -= 50
        if num // 40:
            res.append('XL')
            num -= 40
        if num // 10:
            for _ in range(num // 10):
                res.append('X')
            num %= 10
        if num // 9:
            res.append('IX')
            num -= 9
        if num // 5:
            res.append('V')
            num -= 5
        if num // 4:
            res.append('IV')
            num -= 4
        for _ in range(num):
            res.append('I')
        return ''.join(res)

class Solution:
    digit_map = {
        1: 'I',
        5: 'V',
        10: 'X',
        50: 'L',
        100: 'C',
        500: 'D',
        1000: 'M'
    }
    
    def intToRoman(self, num):
        res = []
        digit = 1000
        while digit > 0:
            tmp = num // digit
            num -= tmp * digit
            if tmp == 9:
                res.append(self.digit_map[digit])
                res.append(self.digit_map[digit * 10])
                tmp -= 9
            if tmp >= 5:
                res.append(self.digit_map[digit * 5])
                tmp -= 5
            if tmp == 4:
                res.append(self.digit_map[digit])
                res.append(self.digit_map[digit * 5])
                tmp -= 4
            for _ in range(tmp):
                res.append(self.digit_map[digit])
            digit //= 10
        return ''.join(res)