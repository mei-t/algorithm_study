def straight_line(screen, width, x1, x2, y):
    line = width * y

    mask = 0
    for _ in range(8 - (x1 % 8)):
        mask <<= 1
        mask += 1
    screen[line + x1 // 8] |= mask

    mask = 0xff
    for i in range((x1 + 8) // 8, x2 // 8):
        screen[line + i] |= mask
    
    mask = 0
    for _ in range(x2 % 8):
        mask <<= 1
        mask += 1
    mask <<= (x2 // 8)
    screen[line + x2 // 8] |= mask

    return screen

if __name__ == '__main__':
    screen = [0] * 20
    width = 5
    straight_line(screen, width, 10, 31, 1)
    for i in range(len(screen) // width):
        for j in range(width):
            byte = screen[i * width + j]
            for k in range(7, -1, -1):
                print(byte >> k & 1, ' ', end='')
            print('| ', end='')
        print('')
