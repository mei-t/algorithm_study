#include <iostream>
using namespace std;

int subtract(int a, int b){
    return a + (~b) + 1;
}

int multi(int sum, int times, int a){
    if(times == 0){
        return sum;
    }
    return multi(sum + a, times - 1, a);
}

int multi(int a, int b){
    bool isMinus = (a > 0) ^ (b > 0);
    int max = abs(a) > abs(b) ? abs(a) : abs(b);
    int min = abs(a) > abs(b) ? abs(b) : abs(a);
    return isMinus ? ~multi(0, min, max) + 1 : multi(0, min, max);
}

int division(int a, int b, int sum, int times){
    if(sum == a){
        return times;
    }
    return division(a, b, sum + b, times + 1);
}

int division(int a, int b){
    bool isMinus = (a < 0) ^ (b < 0);
    return isMinus ? ~division(abs(a), abs(b), 0, 0) + 1 : division(abs(a), abs(b), 0, 0);
}

int main(void){
    cout << subtract(10, 8) << endl; // 2
    cout << subtract(9, -3) << endl; // 12
    cout << multi(3, 8) << endl; // 24
    cout << multi(9, -3) << endl; // -27
    cout << division(10, 2) << endl; // 5
    cout << division(9, -3) << endl; // -3
    return 0;
}