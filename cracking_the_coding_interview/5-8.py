def straight_line(screen, width, x1, x2, y):
    line = width * y

    mask = 0xff
    for i in range((x1 + 8) // 8, x2 // 8):
        screen[line + i] |= mask
    
    l_mask = 0xff
    l_mask >>= (x1 % 8)

    r_mask = 0xff
    r_mask <<= (8 - x2 % 8)

    if x1 // 8 == x2 // 8:
        mask = l_mask & r_mask
        screen[line + x1 // 8] |= mask
    else:
        screen[line + x1 // 8] |= l_mask
        screen[line + x2 // 8] |= r_mask

    return screen

if __name__ == '__main__':
    screen = [0] * 20
    width = 5
    straight_line(screen, width, 10, 11, 1)
    for i in range(len(screen) // width):
        for j in range(width):
            byte = screen[i * width + j]
            for k in range(7, -1, -1):
                print(byte >> k & 1, ' ', end='')
            print('| ', end='')
        print('')
