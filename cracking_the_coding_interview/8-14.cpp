#include <iostream>
#include <unordered_map>
using namespace std;

int countEval(const string& formula, bool res, unordered_map<string, int>& memo){
    if(formula.size() == 0)
        return 0;
    if(formula.size() == 1)
        return stoi(formula) == res ? 1 : 0;
    if(memo.find(formula + to_string(res)) != memo.end()){
        return memo[formula + to_string(res)];
    }
    
    int ways = 0;
    for(size_t i = 1; i < formula.size(); i += 2){
        char c = formula[i];
        string left = formula.substr(0, i);
        string right = formula.substr(i + 1);

        int leftTrue = countEval(left, true, memo);
        int leftFalse = countEval(left, false, memo);
        int rightTrue = countEval(right, true, memo);
        int rightFalse = countEval(right, false, memo);
        int total = (leftTrue + leftFalse) * (rightTrue + rightFalse);

        int totalTrue = 0;
        switch(c){
            case '&':
                totalTrue = leftTrue * rightTrue;
                break;
            case '^':
                totalTrue = leftTrue * rightFalse + leftFalse * rightTrue;
                break;
            case '|':
                totalTrue = total - leftFalse * rightFalse;
        }
        ways += res ? totalTrue : total - totalTrue;
    }
    memo.insert({formula + to_string(res), ways});
    return ways;
}

int countEval(const string& formula, bool res){
    unordered_map<string, int> memo;
    return countEval(formula, res, memo);
}

int main(void){
    string input1 = "1^0|0|1";
    string input2 = "0&0&0&1^1|0";
    cout << countEval(input1, false) << endl;
    cout << countEval(input2, true) << endl;
    return 0;
}