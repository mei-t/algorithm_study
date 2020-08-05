#include <iostream>
#include <queue>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution1 {
public:
    int calculate(string s) {
        int i = 0;
        queue<Component> origin;
        while(i < s.size()){
            switch(s[i]){
                case '+':
                case '-':
                case '*':
                case '/':
                    origin.push({Operator, 0, operatorMap[s[i]]});
                case ' ':
                    i++;
                    break;
                default:
                    int val = 0;
                    while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                        val *= 10;
                        val += s[i] - '0';
                        i++;
                    }
                    origin.push({Operand, val, None});
            }
        }
        origin.push({End, 0, None});

        int prev;
        while(origin.front().type != End){
            Component current = origin.front();
            origin.pop();
            if(current.type == Operand){
                prev = current.val;
            } else if(current.ope == Add || current.ope == Subt){
                origin.push({Operand, prev, None});
                origin.push(current);
            } else {
                Component next = origin.front();
                origin.pop();
                prev = caluculate(prev, next.val, current.ope);
            }
        }
        origin.push({Operand, prev, None});
        origin.pop();

        int ans = 0;
        while(!origin.empty()){
            Component current = origin.front();
            origin.pop();
            if(current.type == Operand){
                ans += current.val;
            }else{
                Component next = origin.front();
                origin.pop();
                ans = caluculate(ans, next.val, current.ope);
            }
        }
        return ans;
    }

private:
    enum Type { Operand, Operator, End};
    enum Ope { Add, Subt, Mult, Divi, None};

    struct Component{
        Type type;
        int val;
        Ope ope;
    };

    unordered_map<char, Ope> operatorMap = {
        {'+', Add},
        {'-', Subt},
        {'*', Mult},
        {'/', Divi}
    };

    int caluculate(int x, int y, Ope ope){
        switch(ope){
            case Add:
                return x + y;
            case Subt:
                return x - y;
            case Mult:
                return x * y;
            case Divi:
                return x / y;
            default:
                return 0;
        }
    }
};

class Solution2 {
public:
    // O(N) time O(1) space
    int calculate(string s) {
        stringstream ss("+" + s);
        char op;
        int n, last, ans = 0;
        while (ss >> op >> n) {
            if (op == '+' || op == '-') {
                n = op == '+' ? n : -n;
                ans += n;
            } else {
                n = op == '*' ? last * n : last / n;
                ans = ans - last + n; // simulate a stack by recovering last values
            }
            last = n;
        }
        return ans;
    }
};

int main(void){
    string s = "3+2*2";
    Solution1 sol1;
    cout << sol1.calculate(s) << endl;

    Solution2 sol2;
    cout << sol2.calculate(s) << endl;
}