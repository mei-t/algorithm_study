#include <iostream>
#include <vector>
#define NUM(c) (c - '0')
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        vector<int> dp(s.size() + 1);
        dp[s.size()] = 1;
        for(int i = s.size() - 1; i >= 0; i--){
            if(NUM(s[i]) == 0){
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i + 1];
            if(i < s.size() - 1 && NUM(s[i]) * 10 + NUM(s[i + 1]) < 27){
                dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};

int main(void){
    Solution sol;
    cout << sol.numDecodings("17") << endl;
    return 0;
}