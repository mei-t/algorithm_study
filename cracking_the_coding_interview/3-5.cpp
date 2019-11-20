#include <iostream>
#include <deque>
#include <stack>
using namespace std;

// 14分39秒(ヒント見た)

void sortStack(stack<int>& input){
    stack<int> largeStack;
    while(!input.empty()){
        int num = input.top();
        input.pop();
        while(!largeStack.empty() && num <= largeStack.top()){
            input.push(largeStack.top());
            largeStack.pop();
        }
        largeStack.push(num);
        while(!input.empty() && input.top() > largeStack.top()){
            largeStack.push(input.top());
            input.pop();
        }
    }

    while(!largeStack.empty()){
        input.push(largeStack.top());
        largeStack.pop();
    }
    return;
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