#include <iostream>
using namespace std;

int computeMulti(int smaller, int bigger){
    if(smaller == 1){
        return bigger;
    }

    int half = computeMulti(smaller / 2, bigger);
    if(smaller % 2){
        bigger = half + bigger;
    }else{
        bigger = half;
    }
    return half + bigger;
}

int multiply(int num1, int num2){
    int smaller = num1 < num2 ? num1 : num2;
    int bigger = num1 < num2 ? num2 : num1;
    return computeMulti(smaller, bigger);
}

int main(void){
    cout << "3 * 5 = " << 3*5 << endl;
    cout << multiply(3, 5) << endl;
    cout << "16 * 83 = " << 16*83 << endl;
    cout << multiply(16, 83) << endl;
    return 0;
}