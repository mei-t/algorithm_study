#include <iostream>
#include <vector>
using namespace std;

// 発展問題はまだ解いてない

int findMagicIndex(const vector<int>& A){
    int left = 0;
    int right = A.size();
    int i;
    while(left < right){
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
    vector<int> A = {-3, -1, 0, 3, 9};
    cout << findMagicIndex(A) << endl;
    return 0;
}