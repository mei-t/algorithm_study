#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

// 26分51秒(含見直し)

class EnglishNumber{
public:
    string createEnglishNum(long num);
    string insertSpace(bool* isFirst, int i = 1);
private:
    unordered_map<int, string> unit = {
        {0, ""}, {1, " thousand"}, {2, " million"}, {3, " billion"}
    };

    unordered_map<int, string> underTwenty = {
        {0, ""}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"},{5, "five"},
        {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"},
        {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"},
        {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"},
        {19, "nineteen"}
    };

    unordered_map<int, string> overTwenty ={
        {2, "twenty"}, {3, "thirty"}, {4, "fourty"}, {5, "fifty"},
        {6, "sixty"}, {7, "seventy"}, {8, "eighty"}, {9, "ninety"}
    };
};

string EnglishNumber::createEnglishNum(long num){
    if(num == 0){
        return "zero";
    }
    stack<int> numStack;
    while(num > 0){
        numStack.push(num % 1000);
        num /= 1000;
    }

    string ans;
    bool isFirst = true;
    while(!numStack.empty()){
        int tmp = numStack.top();
        numStack.pop();
        if(tmp == 0){
            continue;
        }
        if(tmp / 100){
            ans += insertSpace(&isFirst) + underTwenty[tmp / 100] + " hundred";
            tmp %= 100;
        }
        if(tmp >= 20){
            ans += insertSpace(&isFirst) + overTwenty[tmp / 10];
            tmp %= 10;
        }
        ans += insertSpace(&isFirst, tmp) + underTwenty[tmp] + unit[numStack.size()];
    }
    return ans;
};

string EnglishNumber::insertSpace(bool* isFirst, int i){
    string s = "";
    if(i == 0){
        return s;
    }

    if(*isFirst){
        *isFirst = false;
    }else{
        s = " ";
    }
    return s;
}

int main(void){
    EnglishNumber en;
    long num1 = 2238592137;
    cout << num1 << " = " << en.createEnglishNum(num1) << endl;

    long num2 = 20005921300;
    cout << num2 << " = " << en.createEnglishNum(num2) << endl;

    long num3 = 2110000001300;
    cout << num3 << " = " << en.createEnglishNum(num3) << endl;
    return 0;
}