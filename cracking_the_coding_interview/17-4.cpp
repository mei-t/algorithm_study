#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;
static const size_t INT_SIZE = sizeof(int) * 8;
static const size_t LONG_SIZE = sizeof(unsigned long) * 8;

class binNum{
public:
    binNum(int num){
        num_ = num;
    }
    bool getbit(size_t i){
        return num_ & (1 << i);
    }
    int getNum(){
        return num_;
    }

private:
    int num_;
};

unsigned long lostNum(vector<binNum>& nums, size_t i, bitset<LONG_SIZE> b){
    if(nums.empty() || i == INT_SIZE){
        return b.to_ulong();
    }

    int countOne = 0;
    int countZero = 0;
    for(binNum num: nums){
        if(num.getbit(i)){
            countOne++;
        }else{
            countZero++;
        }
    }
    bool isOneAns = countOne < countZero ? true : false;
    if(isOneAns){
        b.set(i);
    }
    for(auto it = nums.begin(); it != nums.end(); ){
        if(it->getbit(i) && !isOneAns){
            nums.erase(it);
        }else if(!it->getbit(i) && isOneAns){
            nums.erase(it);
        }else{
            it++;
        }
    }

    return lostNum(nums, i + 1, b);
}

unsigned long lostNum(vector<binNum>& nums){
    bitset<LONG_SIZE> b;
    return lostNum(nums, 0, b);
}

// うまくいかなかった
unsigned long lostNum2(const vector<binNum>& nums){
    vector<int> countOne(INT_SIZE, 0);
    for(binNum num: nums){
        // cout << "num is " << num.getNum() << endl;
        for(int i=0; i<INT_SIZE; i++){
            if(num.getbit(i)){
                // cout << "i = " << i << ", countOne[i] = " << countOne[i] << endl;
                countOne[i]++;
            }
        }
    }

    size_t size = nums.size();
    bitset<LONG_SIZE> b;
    for(int i=0; countOne[i] > 0; i++){
        int cycle = size / pow(2, i+1);
        // この部分にミスあり
        if(countOne[i] != cycle * pow(2, i) + max(0, cycle % (int)pow(2, i))){
            // cout << i << endl;
            b.set(i);
        }
    }
    return b.to_ulong();
}

int main(void){
    vector<binNum> nums = {0, 1, 2, 3, 4, 5, 7, 8, 9, 10};
    cout << lostNum(nums) << endl; // 6
    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cout << lostNum(nums) << endl; // 0
    nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16};
    cout << lostNum(nums) << endl; // 15
    nums = {0, 1, 2, 3, 4, 5, 7, 8, 9, 10};
    cout << lostNum2(nums) << endl; // 6
    return 0;
}