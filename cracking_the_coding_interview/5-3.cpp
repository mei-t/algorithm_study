#include <iostream>
using namespace std;

int countContinuedOne(int input){
    int pos = 1;
    int ansCount = 0;
    int prevCount = 0;
    int curCount = 0;
    int tmpCount = 0;
    while(pos != 0){
        if(input && pos){
            curCount++;
        }else{
            if(curCount != 0){
                if(prevCount == 0){
                    tmpCount = curCount + 1;
                }else{
                    tmpCount = prevCount + curCount + 1;
                }
                if(tmpCount > ansCount){
                    ansCount = tmpCount;
                }
                prevCount = curCount;
                curCount = 0;
            }else{
                prevCount = 0;
            }
        }
        pos << 1;
    }

    return ansCount;
}

int main(void){
    return 0;
}