#include <iostream>
#include <cmath>
#include <exception>
using namespace std;

double chngeBin (double n){
    double ans = 0.0;
    for (int i = 0; i< 32; i++){
        if(n > 1 / pow(2, i)){
            n -= 1 / pow(2, i);
            ans += 1 >> i;
        }
        if(n == 0.0){
            break;
        }
    }

    if(n != 0.0){
        cout << "ERROR" << endl;
        throw new exception();
    }

    return ans;
}

int main(void){
    return 0;
}