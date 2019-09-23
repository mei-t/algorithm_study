#include <iostream>
using namespace std;

// ex) N: 10011000, M: 011, i: 3, j: 1, ans: 10010110
int setBit(int N, int M, int i, int j) {
    unsigned int top = (~0) << (i + 1); // 11110000
    unsigned int bottom = (1 << j) - 1; // 00000001
    int mask = top | bottom; // 11110001
    return (N & mask) | (M << j);
}

int main(void) {
    cout << "0x" << hex << setBit(0x98, 0x3, 0x3, 0x1) << endl;
    return 0;
}