#include <iostream>
#include <cstddef>
#include <vector>
using namespace std;

void drawLine(vector<byte> screen, int width, int x1, int x2, int y){
    byte b{255};
    if(x1/8 == x2/8){
        screen[(y-1) * width/8 + x1/8] = (b >> (x1%8)) & (b << (x2%8));
        return;
    }
    screen[(y-1) * width/8 + x1/8] = b >> (x1%8);
    for(int i = x1/8 + 1; i < x2/8; i++){
        screen[(y-1)*width/8 + i] = b;
    }
    screen[(y-1) * width/8 + x2/8] = b << (x2%8);
}

int main(void){
    return 0;
}