#include <iostream>
#include <cstddef>
#include <vector>
using namespace std;

void drawLine(vector<byte>& screen, int width, int x1, int x2, int y){
    byte b{255};
    if(x1/8 == x2/8){
        screen[(y-1) * width/8 + x1/8] = (b >> (x1%8)) & (b << (x2%8));
        return;
    }
    cout << to_integer<int>(b) << endl;
    screen[(y-1) * width/8 + x1/8] = b >> (x1%8);
    cout << to_integer<int>(b) << endl;
    for(int i = x1/8 + 1; i < x2/8; i++){
        screen[(y-1)*width/8 + i] = b;
    }
    screen[(y-1) * width/8 + x2/8] = b << (x2%8);
}

void outputByte(byte b){
    for(int i=0; i<8; i++){
        cout << (to_integer<int>(b) & (1 << (8-i))) << " ";
    }
}

void output(vector<byte>& screen, int width){
    for(int i = 0; i < screen.size()/(width/8); i++){
        for(int j = 0; j < width/8; j++){
            outputByte(screen[i+j]);
        }
        cout << endl;
    }
}

int main(void){
    byte b{0};
    vector<byte> screen(25, b);
    drawLine(screen, 40, 3, 28, 3);
    output(screen, 40);
    return 0;
}