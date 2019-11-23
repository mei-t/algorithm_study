#include <iostream>
#include <bitset>
using namespace std;

constexpr size_t size_int = sizeof(int) * 8;

long sum(int num1, int num2){
    bitset<size_int> b(0);
    int carry = 0;
    for (int i = 0; i<size_int; i++){
        cout<< b << endl;
        if((num1 & 1<<i) ^ (num2 & 1<<i) ^ carry){
            cout << "aaa " <<((num1 & 1<<i) ^ (num2 & 1<<i)) << endl;
            cout << "bbb " <<((num1 & 1<<i) ^ (num2 & 1<<i) ^ carry) << endl;
            cout << (num1 & 1<<i) << " " << (num2 & 1<<i) << endl;
            cout << i << "carry: " << carry << endl;
            b.set(i);
            if((num1 & 1<<i) && (num2 & 1<<i) && carry){
                carry = 1;
            }else{
                carry = 0;
            }
        }else{
            // cout << (num1x & 1<<i) << " " << (num2 & 1<<i) << endl;
            // cout << i << "carry: " << carry << endl;
            if((num1 & 1<<i) || (num2 & 1<<i) || carry){
                carry = 1;
            }else{
                carry = 0;
            }
        }
    }

    return b.to_ulong();
}

int main(void){
    cout << sum(3, 5) << endl;
    return 0;
}