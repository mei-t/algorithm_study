#include <iostream>
#include <bitset>
using namespace std;

// 11分43秒
const size_t INT_SIZE = sizeof(int) * 8;

class Bit{
public:
    Bit();
    int changeBit(int num);
private:
    bitset<INT_SIZE> b;
};

Bit::Bit(){
    for(int i=0; i<INT_SIZE; i++){
        if(!(i % 2)){
            b.set(i);
        }
    }
}

int Bit::changeBit(int num){
    int b_int = b.to_ulong();
    int even = num & b_int;
    int odd = num & (b_int << 1);
    return (even << 1) | (odd >> 1);
}

int main(void){
    Bit bit;
    cout << bit.changeBit(5) << endl; // 10
    cout << bit.changeBit(13) << endl; // 14
    cout << bit.changeBit(21) << endl; // 42
    cout << bit.changeBit(30) << endl; // 45
    return 0;
}