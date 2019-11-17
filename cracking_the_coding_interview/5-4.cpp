#include <iostream>
using namespace std;

void nextNumber(int num){
    bool isOneFound = false;
    int firstOneIndex = -1;
    for(int i=0; i<32; i++){
        if(!isOneFound && (num && 1 << i)){
            isOneFound = true;
            num -= 1 << i;
            firstOneIndex = i;
        }else if(isOneFound && !(num && 1 << i)){
            cout << "The next number is " << num + (1 << i) << "." << endl;
            break;
        }
        if(i == 31){
            cout << "The next number isn't found." << endl;
        }
    }
    if(!isOneFound){
        cout << "Error: The input should not be 0." << endl;
        return;
    }

    for(int i = firstOneIndex - 1; i >= 0; i--){
        if(!(num && 1 << i)){
            cout << "The previous number is " << num + (1 << i) << "." << endl;
            break;
        }
        if(i == 0){
            cout << "The previous number isn't found." << endl;
        }
    }
    return;
}

int main(void){
    nextNumber(8);
    nextNumber(1);
    nextNumber(0);
    return 0;
}