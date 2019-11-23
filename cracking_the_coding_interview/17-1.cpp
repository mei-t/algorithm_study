#include <iostream>
#include <bitset>
using namespace std;

constexpr size_t size_int = sizeof(int) * 8;

// add()の方がいいやり方
long sumWithBitset(int num1, int num2){
    bitset<size_int> b(0);
    int carry = 0;
    for (int i = 0; i<size_int; i++){
        if(((num1 & 1<<i) && true) ^ ((num2 & 1<<i) && true) ^ carry){
            b.set(i);
            if((num1 & 1<<i) && (num2 & 1<<i) && carry){
                carry = 1;
            }else{
                carry = 0;
            }
        }else{
            if((num1 & 1<<i) || (num2 & 1<<i) || carry){
                carry = 1;
            }else{
                carry = 0;
            }
        }
    }

    return b.to_ulong();
}

int add(int num1, int num2){
    if(!num2){
        return num1;
    }

    int sum = num1 ^ num2;
    int carry = (num1 & num2) << 1;
    return add(sum, carry);
}

int main(void){
    cout << sumWithBitset(3, 5) << endl;
    cout << add(3, 5) << endl;
    return 0;
}