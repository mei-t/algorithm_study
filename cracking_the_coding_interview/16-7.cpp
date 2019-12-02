#include <iostream>
using namespace std;
static const size_t SIZE_INT = sizeof(int) * 8;

int compare(int a, int b){
    bool isAMinus = a & (1 << (SIZE_INT - 1));
    bool isBMinus = b & (1 << (SIZE_INT - 1));
    bool found = isAMinus ^ isBMinus;
    int max = !isAMinus * a + !isBMinus * b;
    for(int i = SIZE_INT - 2; !found && i >= 0; i--){
        bool isA = a & (1 << i);
        bool isB = b & (1 << i);
        found = isA ^ isB;
        max = isA * a + isB * b;
    }
    return max;
}

int compare2(int a, int b){
    bool isAMinus = a & (1 << (SIZE_INT - 1));
    bool isBMinus = b & (1 << (SIZE_INT - 1));
    bool isSignDiff = isAMinus ^ isBMinus;
    bool isAMax = (b - a) & (1 << (SIZE_INT - 1));
    bool isBMax = (a - b) & (1 << (SIZE_INT - 1));
    return (!isAMinus * a + !isBMinus * b) * isSignDiff + (isAMax * a + isBMax * b) * !isSignDiff;
}

int main(void){
    cout << compare(10, 2) << endl; // 10
    cout << compare2(10, 2) << endl; // 10
    cout << compare(-25, 7) << endl; // 7
    cout << compare2(-25, 7) << endl; // 7
    cout << compare(-12, -3) << endl; // -3
    cout << compare2(-12, -3) << endl; // -3
    return 0;
}