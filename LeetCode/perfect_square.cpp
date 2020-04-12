#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int sq = checkMaxSquare(n);
        cout << sq << endl;
        return numSquares(n, checkMaxSquare(n), 0, INT_MAX);
    }
private:
    unordered_map<int, int> countMap;
    // unordered_map<int, int> squareMap;
    int numSquares(int n, int sq, int count, int tmp){
        // cout << "sq = " << sq << endl;
        // cout << "n = " << n << endl;
        if(tmp <= count){
            return tmp;
        }else if(n - sq*sq == 0){
            // cout << "n = " << n << ", sq = " << sq << endl;
            return count + 1;
        }else if(countMap.find(n) != countMap.end()){
            return countMap[n];
        }
        int ans;
        if(sq == 1){
            ans = count + n;
        }else{
            if(n == 7168 && sq == 80){
                cout << "n - sq*sq = " << n - sq*sq  << ", checkMaxSquare(n - sq*sq) = " << checkMaxSquare(n - sq*sq) << endl;
                cout << "cout = " << count << endl;
            }
            int includeSq = numSquares(n - sq*sq, checkMaxSquare(n - sq*sq), count + 1, INT_MAX);
            int excludeSq = numSquares(n, sq - 1, count, includeSq);
            ans = min(includeSq, excludeSq);
            if(n == 7168 && sq == 80){
                cout << "ans = " << ans << ", includeSq = " << includeSq << endl;
            }
        }
        countMap.insert({n, ans});
        return ans;
    }

    int checkMaxSquare(int n){
        int ans = 1;
        for(int i=1; i<n; i++){
            if((i+1)*(i+1) > n){
                ans = i;
                break;
            }
        }
        // cout << n << ", ans = " << ans << endl;
        // squareMap.insert({n,})
        return ans;
    }
};

int main(void){
    Solution sol;
    // cout << sol.numSquares(768) << endl;
    cout << sol.numSquares(7168) << endl;
    return 0;
}