#include <iostream>
#include <bitset>
using namespace std;

constexpr size_t size_int = sizeof(int) * 8;

pair<bool, bool> add1Bit(bool a, bool b){
    return make_pair(a ^ b, a & b);
}

pair<bool, bool> addBitWithCarry(bool a, bool b, bool carry){
    // pair<bool, bool> tmp1 = add1Bit(a, b);
    // pair<bool, bool> tmp2 = add1Bit(tmp1.first, carry);
    bool sum = a ^ b ^ carry;
    bool carry = (a & b) | (a & carry) | (b & carry);
    // return make_pair(tmp2.first, tmp1.second | tmp2.second);
    return make_pair(sum, carry);
}

#define BIT(i, n) ((i >> n) & 1)

pair<unsigned int, bool> sumAre(unsigned int num1, unsigned int num2){
    bool carry = false;
    unsigned int ans = 0;
    for(size_t i = 0; i < size_int; i++){
        pair<bool, bool> t = addBitWithCarry(BIT(num1, i), BIT(num2, i), carry);
        ans |= t.first;
        carry = t.second;
    }
    return make_pair(ans, carry);
}

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