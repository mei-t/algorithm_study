#include <iostream>
using namespace std;

// ex) N: 10011000, M: 011, i: 3, j: 1, ans: 10010110
int setBit(int N, int M, int i, int j) {
    int top = -1 << (i + 1); // 11110000
    int bottom = ~(-1 << j); // 00000001
    int mask = top | bottom; // 11110001
    return (N & mask) | (M << j);
}

int main(void) {
    cout << setBit(-104, 3, 3, 1) << endl;
    return 0;
}