#include <iostream>
#include <stack>
using namespace std;

// 17分23秒

template<typename T>
class SetOfStack:public stack<T> {
    public:
    SetOfStack(int capacity){
        capacity_ = capacity;
        stack<T> newStack = new stack<T>();
        stackStack.push(newStack);
    }

    void push(T a){
        stack<T> curStack = stackStack.top();
        stackStack.pop();
        if(curStack.size() == capacity_) {
            curStack.push(a);
            stackStack.push(curStack);
        } else {
            stack<T> newStack = new stack<T>();
            newStack.push(a);
            stackStack.push(curStack);
            stackStack.push(newStack);
        }
    }

    void pop(){
        stack<T> curStack = stackStack.top();
        curStack.pop();
        if(curStack.empty()) {
            delete curStack;
        } else {
            stackStack.push(curStack);
        }
    }

    private:
    stack<stack<T>> stackStack;
    int capacity_;
};

int main(void) {
    return 0;
}