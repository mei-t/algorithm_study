#include <iostream>
#include <vector>
#define NUM(c) c - '0'
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
            if(i < s.size() - 1 && NUM(s[i]) < 3 && NUM(s[i + 1]) < 7){
                dp[i] += dp[i + 2];
                cout << "NUM(s[i]) * 10 + NUM(s[i + 1]) = " << (NUM(s[i]) * 10) + NUM(s[i + 1]) << endl;
                cout << "NUM(s[i]) = " << NUM(s[i]) << endl;
                cout << "NUM(s[i]) * 10 = " << NUM(s[i]) * 10 << endl;
                cout << "NUM(s[i + 1]) = " << NUM(s[i + 1]) << endl;
            }
        }
        return dp[0];
    }
};

int main(void){
    Solution sol;
    cout << sol.numDecodings("27") << endl;
    return 0;
}