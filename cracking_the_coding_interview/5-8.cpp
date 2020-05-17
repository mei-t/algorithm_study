#include <iostream>
#include <cstddef>
#include <vector>
using namespace std;

void drawLine(vector<char>& screen, int width, int x1, int x2, int y){
    int stride = width/8;
    int line_y = y * stride;
    int start_block = x1/8;
    int end_block = x2/8;
    if(start_block == end_block){
        cout << (0xFF >> (x1%8)) << endl;
        cout << (0xFF << (x2%8)) << endl;
        cout << ((0xFF >> ((x1-1)%8)) & (0xFF << (x2%8))) << endl;
        screen[line_y + start_block] = (0xFF >> ((x1-1)%8)) & (0xFF << (x2%8));
        return;
    }
    screen[line_y + start_block] = 0xFF >> ((x1-1)%8);
    for(int i = x1/8 + 1; i < x2/8; i++){
        screen[line_y + i] = 0xFF;
    }
    screen[line_y + end_block] = 0xFF << (x2%8);
}

void outputByte(char c){
    for(int i=0; i<8; i++){
        cout << ((c & (1 << (8-i))) ? 1 : 0) << " ";
    }
}

void output(vector<char>& screen, int width){
    int stride = width/8;
    for (int i = 0; i < screen.size(); i++){
        outputByte(screen[i]);
        if((i + 1) % stride == 0)
            cout << endl;
    }
}

int main(void){
    vector<char> screen1(25, 0);
    drawLine(screen1, 40, 3, 28, 3);
    output(screen1, 40);
    vector<char> screen2(25, 0);
    drawLine(screen2, 40, 3, 5, 3);
    output(screen2, 40);
    return 0;
}