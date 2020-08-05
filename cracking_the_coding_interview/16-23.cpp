#include <iostream>
#include <random>
using namespace std;

int rand5(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 4);
    return distrib(gen);
}

int rand7(){
    while(true){
        int num = 5 * rand5() + rand5();
        if(num < 21)
            return num % 7;
    }
}

int main(void){
    for(int i = 0; i < 5; i++){
        cout << rand7() << endl;
    }
    return 0;
}