#include <iostream>
using namespace std;

// 7分59秒

int countLastZeroInFactorial(int num, int count){
    num /= 5;
    if(num == 0){
        return count;
    }
    count += num;
    return countLastZeroInFactorial(num, count);
}

int countLastZeroInFactorial(int num){
    return countLastZeroInFactorial(num, 0);
}

long computeFactorial(int num){
    if(num == 1){
        return 1;
    }
    return (num * computeFactorial(num - 1)) % 10000000000000;
}

int main(void){
    cout << countLastZeroInFactorial(8) << endl;
    cout << computeFactorial(8) << endl;
    cout << countLastZeroInFactorial(52) << endl;
    cout << computeFactorial(52) << endl;
    return 0;
}