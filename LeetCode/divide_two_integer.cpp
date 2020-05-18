#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int divide(long long dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1: 1;
        long long num = abs(dividend);
        divisor = abs(divisor);
        long long ans = 0;
        while(num >= divisor){
            long long div = divisor;
            int tmp = 1;
            while(num >= (div << 1)){
                div <<= 1;
                tmp <<= 1;
            }
            num -= div;
            ans += tmp;
        }
        return sign * ans;
    }
};

int main(void){
    Solution sol;
    cout << sol.divide(-2147483648, 1) << endl;;
    // cout << sol.divide(-2147483648, -1) << endl;;
    return 0;
}