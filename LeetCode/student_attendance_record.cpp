#include <iostream>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int absent_count = 0;
        int continuous_late_count = 0;
        for(char c: s){
            if(c == 'L'){
                continuous_late_count++;
            }else{
                continuous_late_count = 0;
            }
            if(c == 'A'){
                absent_count++;
            }
            if(continuous_late_count > 2 || absent_count > 1){
                return false;
            }
        }
        return true;
    }
};