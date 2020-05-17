#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    long divide(long dividend, int divisor) {
        bool isPositive = true;
        if((dividend < 0) ^ (divisor < 0)){
            isPositive = false;
        }
        long num = abs(dividend);
        divisor = abs(divisor);
        long ans = 0;
        while(num >= divisor){
            // cout << num << " " << divisor << endl;
            num -= divisor;
            ans++;
        }
        cout << ans << endl;
        cout << "isPositive = " << isPositive << endl;
        ans = isPositive ? ans : -1 * ans;
        cout << ans << endl;
        return ans;
        // return isPositive ? ans : -1 * ans;
    }
};

int main(void){
    Solution sol;
    cout << sol.divide(-2147483648, -1) << endl;;
    return 0;
}