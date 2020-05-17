#include <iostream>
#include <cstddef>
#include <vector>
#define INDEX(x, y, width) ((y * (width/8) + x))
#define WIDTH_BLOCK(width) (width/8)
using namespace std;

void drawLine(vector<char>& screen, int width, int x1, int x2, int y){
    if(x1/8 == x2/8){
        screen[(y-1) * width/8 + x1/8] = (~0 >> (x1%8)) & (~0 << (x2%8));
        return;
    }
    cout << "x1%8 = " << x1%8 << endl;
    cout << "~0 >> (x1%8) = " << (~0 >> (x1%8)) << endl;
    cout << ~0 << endl;
    cout << "0xFF >> (x1%8) = " << (0xFF >> (x1%8)) << endl;
    cout << 0xFF << endl;
    screen[(y-1) * width/8 + x1/8] = ~0 >> (x1%8);
    for(int i = x1/8 + 1; i < x2/8; i++){
        screen[(y-1)*width/8 + i] = 0xFF;
    }
    screen[(y-1) * width/8 + x2/8] = ~0 << (x2%8);
}

void outputByte(char c){
    for(int i=0; i<8; i++){
        cout << ((c & (1 << (8-i))) ? 1 : 0) << " ";
    }
}

void output(vector<char>& screen, int width){
    for (int i = 0; i < screen.size(); i++){
        // cout << "screen[" << i << "] = " << hex << (int)screen[i] << endl;
        outputByte(screen[i]);
        if((i + 1) % WIDTH_BLOCK(width) == 0)
            cout << endl;
    }
}

int main(void){
    vector<char> screen(25, 0);
    drawLine(screen, 40, 3, 28, 3);
    output(screen, 40);
    return 0;
}