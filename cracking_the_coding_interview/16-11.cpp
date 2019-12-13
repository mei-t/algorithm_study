#include <iostream>
#include <vector>
using namespace std;

// 8分?

vector<int> computeAllLength(int s, int l, int k){
    vector<int> ans;
    for(int i = 0; i <= k; i++){
        ans.push_back(s * i + l * (k - i));
    }
    return ans;
}

int main(void){
    return 0;
}