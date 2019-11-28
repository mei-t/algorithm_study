#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinDiff(vector<int>& v1, vector<int>& v2){
    if(v1.empty() || v2.empty()){
        return -1; // error
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> checkAll = v1[v1.size()-1] < v2[v2.size()-1] ? v1 : v2; 
    vector<int> checkDiff = v1[v1.size()-1] >= v2[v2.size()-1] ? v1 : v2;

    int minDiff = INT_MAX;
    int cdPos = 0;
    for (int num: checkAll){
        int diff = INT_MAX;
        for(; cdPos < checkDiff.size(); cdPos++){
            cout << num - checkDiff[cdPos] << endl;
            if(abs(diff) < abs(num - checkDiff[cdPos])){
                break;
            }
            diff = num - checkDiff[cdPos];
        }
        cdPos--;
        diff = abs(diff);
        if(minDiff > diff){
            minDiff = diff;
        }
    }
    return minDiff;
}

int main(void){
    vector<int> v1 = {1, 2, 3, 11, 15};
    vector<int> v2 = {8, 19, 23, 127, 235};
    cout << findMinDiff(v1, v2) << endl;
    return 0;
}