#include <iostream>
#include <deque>
#include <stack>
using namespace std;

// 14分39秒(ヒント見た)

stack<int> sortStack(stack<int>& input){
    stack<int> largeStack, tmpStack;
    while(!input.empty()){
        int num = input.top();
        input.pop();
        while(!largeStack.empty() && num >= largeStack.top()){
            tmpStack.push(largeStack.top());
            largeStack.pop();
        }
        largeStack.push(num);
        while(!tmpStack.empty()){
            largeStack.push(tmpStack.top());
            tmpStack.pop();
        }
    }

    while(!largeStack.empty()){
        input.push(largeStack.top());
        largeStack.pop();
    }
    return input;
}

int main(void){
    deque<int> content = {0, 15, 2, 10, 8, 3};
    stack<int> input(content);
    sortStack(input);
    while(!input.empty()){
        cout << input.top() << " ";
        input.pop();
    }
    cout << endl;
    return 0;
}