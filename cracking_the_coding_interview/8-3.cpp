#include <iostream>
using namespace std;

// 発展問題はまだ解いてない

int findMagicIndex(const int A[]){
    int left = 0;
    int right = sizeof(A) / sizeof(A[0]);
    cout << right << endl;
    int i;
    while(left > right){
        i = (left + right) / 2;
        if(A[i] == i){
            return i;
        }else if(A[i] < i){
            left = i;
        }else{
            right = i;
        }
    }
    return -1;
}

int main(void){
    int A[5] = {-3, -1, 0, 3, 9};
    cout << findMagicIndex(A) << endl;
    return 0;
}