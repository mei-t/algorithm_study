#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        if(numerator == 0)
            return "0";
        
        string res;
        if((0 > numerator) ^ (0 > denominator))
            res += "-";
        
        numerator = labs(numerator);
        denominator = labs(denominator);
        long r = numerator % denominator;
        res += to_string(numerator / denominator);
        if(!r)
            return res;

        res += ".";

        unordered_map<int, int> map;
        while(r){
            if(map.count(r)){
                res.insert(map[r], "(");
                res += ")";
                break;
            }
            map.insert({r, res.size()});
            r *= 10;
            res += to_string(r / denominator);
            r %= denominator;
        }
        return res;
    }
};

int main(void){
    Solution sol;
    cout << sol.fractionToDecimal(4, 2) << endl;
    cout << sol.fractionToDecimal(1, 2) << endl;
    cout << sol.fractionToDecimal(2, 3) << endl;
    cout << sol.fractionToDecimal(-2147483648, 1) << endl;
    return 0;
}