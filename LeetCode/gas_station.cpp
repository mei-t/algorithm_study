#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        int total = 0;
        for(int i = 0; i < gas.size(); i++){
            int tmp = gas[i] - cost[i];
            diff.push_back(tmp);
            total += tmp;
        }
        if(total < 0){
            return false;
        }
        
        int ans = -1;
        for(int i = 0; i < diff.size(); i++){
            if(diff[i] >= 0 && canCompleteCircuit(diff, i)){
                return i;
            }
        }
        return ans;
    }

private:
    bool canCompleteCircuit(const vector<int>& diff, int num){
        int total = 0;
        return canGoPartly(diff, num, diff.size(), &total) && canGoPartly(diff, 0, num, &total);
    }

    bool canGoPartly(const vector<int>& diff, int start, int end, int* total){
        for(int i = start; i < end; i++){
            *total += diff[i];
            if(*total < 0){
                return false;
            }
        }
        return true;
    }
};

int main(void){
    return 0;
}