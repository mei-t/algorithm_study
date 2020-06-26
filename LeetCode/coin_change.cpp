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
        if(coins[index] == amount)
            return 1;
        if(index == 0 && coins[index] > amount)
            return -1;
        string key = to_string(index) + " " + to_string(amount);
        if(numMap.find(key) != numMap.end())
            return numMap[key];
        int x = -1, y = -1;
        if(coins[index] < amount ) {
            x = coinChange(coins, amount - coins[index], index);
            x = (x == -1 ? -1 : x + 1);
        }
        if(index > 0)
            y = coinChange(coins, amount, index - 1);
        int ans;
        if(x == -1 && y == -1) {
            ans = -1;
        } else if(x == -1) {
            ans = y;
        } else if(y == -1) {
            ans = x;
        } else {
            ans = min(x, y);
        }
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