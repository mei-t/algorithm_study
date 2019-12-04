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

unsigned long lostNum(const vector<binNum>& nums){
    vector<int> countOne(INT_SIZE, 0);
    for(binNum num: nums){
        cout << "num is " << num.getNum() << endl;
        for(int i=0; i<INT_SIZE; i++){
            if(num.getbit(i)){
                cout << "i = " << i << ", countOne[i] = " << countOne[i] << endl;
                countOne[i]++;
            }
        }
    }

    size_t size = nums.size();
    bitset<LONG_SIZE> b;
    for(int i=0; countOne[i] > 0; i++){
        int cycle = size / pow(2, i+1);
        if(countOne[i] != cycle * pow(2, i) + max(0, cycle % (int)pow(2, i))){
            cout << i << endl;
            b.set(i);
        }
    }
    return b.to_ulong();
}

int main(void){
    vector<binNum> nums = {0, 1, 2, 3, 4, 5, 7, 8, 9, 10};
    cout << lostNum(nums) << endl;
    return 0;
}