#include <iostream>
using namespace std;

int signInversion(int a){
    int sign = a > 0 ? 1 : -1;
    int delta = sign;
    int res = 0;
    while(a != 0){
        bool diffSign = (a + delta > 0) != (a > 0);
        if(a + delta != 0 && diffSign){
            delta = sign;
        }
        res += delta;
        a += delta;
        delta += delta;
    }
    return res;
}

int subtract(int a, int b){
    return a + signInversion(b);
}

int abs(int a){
    return a > 0 ? a : signInversion(a);
}

int multi(int sum, int times, int a){
    if(times == 0){
        return sum;
    }
    return multi(sum + a, times - 1, a);
}

int multi(int a, int b){
    bool isMinus = (a > 0) != (b > 0);
    int absA = abs(a);
    int absB = abs(b);
    int max = absA > absB ? absA : absB;
    int min = absA > absB ? absB : absA;
    return isMinus ? signInversion(multi(0, min, max)) : multi(0, min, max);
}

int division(int a, int b, int sum, int times){
    if(sum == a){
        return times;
    }
    return division(a, b, sum + b, times + 1);
}

int division(int a, int b){
    bool isMinus = (a < 0) != (b < 0);
    return isMinus ? signInversion(division(abs(a), abs(b), 0, 0)) : division(abs(a), abs(b), 0, 0);
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