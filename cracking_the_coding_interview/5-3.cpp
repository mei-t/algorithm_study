#include <iostream>
using namespace std;

int countContinuedOne(int input){
    int pos = 1;
    unsigned int ansCount = 0;
    int prevCount = 0;
    int curCount = 0;
    while(pos != 0){
        if(input & pos){
            curCount++;
        }else{
            int tmpCount = prevCount + curCount + 1;
            if(tmpCount > ansCount){
                ansCount = tmpCount;
            }
            prevCount = curCount;
            curCount = 0;
        }
        pos <<= 1;
    }
    int tmpCount = prevCount + curCount + 1;
    if(tmpCount > ansCount){
        ansCount = tmpCount;
    }
    return min(ansCount, sizeof(int)*8);
}

int main(void){
    return 0;
}