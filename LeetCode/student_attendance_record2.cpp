#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        if(n == 0){
            return 0;
        }
        // vectorに条件ごとのcountを記録する
        // vectorのindexと意味の対応は以下
        // ex) v[i]: {the number of continuous L}, {if A appeared}
        // v[0]: 0, false
        // v[1]: 0, true
        // v[2]: 1, false
        // v[3]: 1, true
        // v[4]: 2, false
        // v[5]: 2, true
        vector<long> recSet = { 1, 0, 0, 0, 0, 0};
        for(int i = 0; i < n; i++){
            vector<long> tmp = recSet;
            recSet[0] = (tmp[0] + tmp[2] + tmp[4]) % (int)(pow(10, 9) + 7);
            recSet[1] = (tmp[0] + tmp[1] + tmp[2] + tmp[3] + tmp[4] + tmp[5]) % (int)(pow(10, 9) + 7);
            recSet[2] = tmp[0];
            recSet[3] = tmp[1];
            recSet[4] = tmp[2];
            recSet[5] = tmp[3];
        }
        long ans = 0;
        for(int i = 0; i < 6; i++){
            ans += recSet[i];
        }
        return ans % (int)(pow(10, 9) + 7);
    }
};

int main(void){
    return 0;
}