#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> partition;
        dfs(s, partition, res);
        return res;
    }

private:
    void dfs(string s, vector<string>& partition, vector<vector<string>>& res){
        if(s.empty()){
            res.push_back(partition);
            return;
        }
        for(int i = 1; i <= s.size(); i++){
            if(isPalind(s.substr(0, i))){
                partition.push_back(s.substr(0, i));
                dfs(s.substr(i), partition, res);
                partition.pop_back();
            }
        }
    }

    bool isPalind(string s){
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        return s == s_rev;
    }
};

int main(void){
    string s = "ababb";
    Solution sol;
    vector<vector<string>> ans = sol.partition(s);
    for(auto& partitions: ans){
        for(string partition: partitions){
            cout << partition << " ";
        }
        cout << endl;
    }
    return 0;
}