#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 発展問題
int findMagicIndex(const vector<int>& A, int left, int right){
    if(left > right){
        return -1;
    }

    int i = (left + right) / 2;

    if(A[i] == i){
        return i;
    }
    
    // 左側
    int newRight = min(i - 1, A[i]);
    int leftResult = findMagicIndex(A, left, newRight);
    if(leftResult >= 0){
        return leftResult;
    }

    // 右側
    int newLeft = max(i + 1, A[i]);
    return findMagicIndex(A, newLeft, right);
}

int findMagicIndex(const vector<int>& A){
    return findMagicIndex(A, 0, A.size() - 1);
}

int findMagicIndexWithoutDuplicate(const vector<int>& A){
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
    cout << findMagicIndex(A) << endl; // 3

    vector<int> B = {-3, 3, 3, 3, 3};
    cout << findMagicIndex(B) << endl; // 3
    return 0;
}