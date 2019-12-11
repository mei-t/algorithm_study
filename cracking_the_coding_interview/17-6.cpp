#include <iostream>
using namespace std;

int countTwo(int num){
    int ans = 0;
    long i = 1;
    bool isCloseToMax = false;
    cout << "num/(i*10) = " << num / (i * 10) << endl;
    while(num / i){
        ans += (num / (i * 10)) * i + min(max(num % (i * 10) - i * 2 + 1, 0l), i);
        if(i > INT_MAX / 10){
            isCloseToMax = true;
            break;
        }
        i *= 10;
    }
    return ans;
}

int main(void){
    cout << countTwo(2) << endl; // 1;
    cout << countTwo(25) << endl; // 9
    cout << countTwo(100) << endl; // 20
    cout << countTwo(INT_MAX) << endl;
    return 0;
}