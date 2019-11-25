#include <iostream>
using namespace std;

// 16分36秒

void nextNumber(int num){
    bool isOneFound = false;
    int firstOneIndex = -1;
    for(int i=0; i<32; i++){
        if(num & (1 << i)){
            isOneFound = true;
            num -= 1 << i;
            firstOneIndex = i;
            break;
        }
    }
    
    if(!isOneFound){
        cout << "Error: The input should not be 0." << endl;
        return;
    }

    int i;
    for(i=firstOneIndex + 1; i<32; i++){
        if(!(num & (1 << i))){
            cout << "The next number is " << num + (1 << i) << "." << endl;
            break;
        }
    }
    if(i >= 32){
        cout << "The next number isn't found." << endl;
    }

    for(i = firstOneIndex - 1; i >= 0; i--){
        if(!(num & (1 << i))){
            cout << "The previous number is " << num + (1 << i) << "." << endl;
            break;
        }
    }
    if (i < 0) {
        cout << "The previous number isn't found." << endl;
    }
    return;
}

int main(void){
    nextNumber(8); // next: 16, prev: 4
    nextNumber(1); // next: 2, prev: none
    nextNumber(0); // error
    return 0;
}