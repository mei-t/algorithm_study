#include <iostream>
#include <vector>
#include <unordered_set>
#include <bitset>
using namespace std;

// 4KBに戻り値のメモリを含まないと考える場合
unordered_set<int> findDupliNum(const vector<int>& nums){
    bitset<32000> b;
    unordered_set<int> ans;
    for(int num: nums){
        if(b[num]){
            ans.insert(num);
        }
        b.set(num);
    }
    return ans;
}

// 4KBに戻り値のメモリも含むと考える場合
// 但し重複が4回以上の場合戻り値に重複要素が含まれてしまう
vector<int>& findDupliNum2(vector<int>* nums){
    bitset<32000> b;
    for(auto itr = nums->begin(); itr != nums->end();){
        if(b[*itr]){
            itr++;
            b.reset(*itr);
        }else{
            b.set(*itr);
            nums->erase(itr);
        }
    }
    return *nums;
}

int main(void){
    return 0;
}