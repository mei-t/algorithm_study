#include <iostream>
#include <cassert>
using namespace std;

int countBitDiff(int num1, int num2){
    int diff = num1 ^ num2;
    int maxNum = max(num1, num2);
    int i = 0;
    int count = 0;
    while(maxNum){
        if(diff & 1 << i){
            count++;
        }
        i++;
        maxNum /= 2;
    }
    return count;
}

int main(void){
    int result = countBitDiff(29, 15);
    cout << result << endl;
    assert(result == 2);
    return 0;
}