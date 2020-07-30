#include <iostream>
using namespace std;

// int countEval(string formula, bool res, int index){
//     if(formula.size() == 1)
//         return ~((formula[0] - '0') ^ res);
//     if(index >= formula.size())
//         return 0;
    
//     int ans = countEval(formula, res, index + 2);

//     int val;
//     int x = formula[index - 1] - '0';
//     int y = formula[index + 1] - '0';
//     switch(formula[index]){
//         case '&':
//             val = x & y;
//             break;
//         case '|':
//             val = x | y;
//             break;
//         case '^':
//             val = x ^ y;
//     }
//     formula = formula.substr(0, index - 1) + to_string(val) + formula.substr(index + 2);
//     ans += countEval(formula, res, index);
//     return ans;
// }

// int countEval(string formula, bool res){
//     return countEval(formula, res, 1);
// }

int countEval(string formula, bool res){
    if(formula.size() == 0)
        return 0;
    if(formula.size() == 1){
        cout << formula << ", res = " << res << "toi(formula) == res ? " << (stoi(formula) == res) << endl;
        return stoi(formula) == res ? 1 : 0;
    }
    
    int ways = 0;
    for(int i = 1; i < formula.size(); i += 2){
        char c = formula[i];
        string left = formula.substr(0, i);
        string right = formula.substr(i + 1);

        int leftTrue = countEval(left, true);
        int leftFalse = countEval(left, false);
        int rightTrue = countEval(right, true);
        int rightFalse = countEval(right, false);
        int total = (leftTrue + leftFalse) * (rightTrue + rightFalse);

        int totalTrue = 0;
        switch(c){
            case '&':
                totalTrue = leftTrue + rightTrue;
                break;
            case '^':
                totalTrue = leftTrue * rightFalse + leftFalse * rightTrue;
                break;
            case '|':
                // totalTrue = leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
                totalTrue = total - leftFalse * rightFalse;
        }
        ways += res ? totalTrue : total - totalTrue;
    }
    return ways;
}

int main(void){
    string input1 = "1^0|0|1";
    string input2 = "0&0&0&1^1|0";
    // cout << countEval(input1, false) << endl;
    cout << countEval(input2, true) << endl;
    return 0;
}