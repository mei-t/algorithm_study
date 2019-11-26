#include <iostream>
#include <cassert>
using namespace std;

int countBitDiff(int num1, int num2){
    int count = 0;
    for (int diff = num1 ^ num2; diff != 0; diff = diff & (diff - 1)){
        count++;
    }
    return count;
}

int main(void){
    int result = countBitDiff(29, 15);
    cout << result << endl;
    assert(result == 2);
    return 0;
}