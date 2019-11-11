#include <iostream>
using namespace std;

void swap(int a, int b){
    b = a - b;
    a -= b;
    b += a;
}

void swap2(int a, int b){
    a = a^b;
    b = a^b;
    a = a^b;
}

int main(void){
    return 0;
}