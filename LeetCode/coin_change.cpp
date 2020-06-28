#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        sort(coins.begin(), coins.end());
        return coinChange(coins, amount, coins.size() - 1);
    }
private:
    unordered_map<string, int> numMap;
    int coinChange(const vector<int>& coins, int amount, int index) {
        if(amount == 0)
            return 0;
        if(amount < 0 || index < 0)
            return -1;
        string key = to_string(index) + " " + to_string(amount);
        if(numMap.find(key) != numMap.end())
            return numMap[key];
        int max = amount / coins[index];
        int ans = INT_MAX;
        for(int i = max; i >= 0; i--) {
            int cur = coinChange(coins, amount - coins[index] * i, index - 1);
            if(cur != -1)
                ans = min(ans, cur + i);
        }
        if(ans == INT_MAX)
            ans = -1;
        numMap.insert({key, ans});
        return ans;
    }
};

int main(void){
    vector<int> coins1 = {1, 2, 5};
    Solution sol;
    cout << sol.coinChange(coins1, 11) << endl;
    vector<int> coins2 = {139, 442, 147, 461, 244, 225, 28, 378, 371};
    cout << sol.coinChange(coins2, 9914) << endl;
    return 0;
}