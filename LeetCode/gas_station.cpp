#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        int total = 0;
        int tank = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++){
            int tmp = gas[i] - cost[i];
            total += tmp;
            tank += tmp;
            if(tank < 0){
                start = i + 1;
                tank = 0;
            }
        }
        if(total < 0){
            return -1;
        }
        return start;
    }
};

// class Solution is better solution.
class Solution2 {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        vector<int> diff;
        int total = 0;
        for(int i = 0; i < gas.size(); i++){
            int tmp = gas[i] - cost[i];
            diff.push_back(tmp);
            total += tmp;
        }
        if(total < 0){
            return -1;
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
    vector<int> gas = { 1, 2, 3, 4, 5 };
    vector<int> cost = { 3, 4, 5, 1, 2 };
    Solution sol;
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    return 0;
}