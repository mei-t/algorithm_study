#include <iostream>
#include <vector>
#include <stack>
using namespace std;

enum Operator {Plus, Minus, Prod, Divi};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        for (string token: tokens) {
            if(token == "+") {
                calculate(Plus);
            } else if(token == "-") {
                calculate(Minus);
            } else if(token == "*") {
                calculate(Prod);
            } else if(token == "/") {
                calculate(Divi);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
private:
    stack<int> s;
    void calculate(Operator ope) {
        int y = s.top();
        s.pop();
        int x = s.top();
        s.pop();
        switch(ope) {
            case Plus:
                s.push(x + y);
                break;
            case Minus:
                s.push(x - y);
                break;
            case Prod:
                s.push(x * y);
                break;
            case Divi:
                s.push(x / y);
                break;
        }
    }
};

int main(void){
    Solution s;
    vector<string> input = {"2", "1", "+", "3", "*"};
    cout << s.evalRPN(input) << endl;
    return 0;
}