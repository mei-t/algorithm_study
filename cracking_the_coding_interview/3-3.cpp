#include <iostream>
#include <stack>
using namespace std;

// 17分23秒

template<typename T>
class SetOfStack{
    public:
    SetOfStack(int capacity){
        capacity_ = capacity;
    }

    void push(T a){
        if(stackStack.empty()){
            stack<T> newStack = stack<T>();
            stackStack.push(newStack);
        }
        stack<T>& curStack = stackStack.top();
        if(curStack.size() < capacity_) {
            curStack.push(a);
        } else {
            stack<T> newStack = stack<T>();
            newStack.push(a);
            stackStack.push(newStack);
        }
    }

    void pop(){
        if(stackStack.empty()){
            return;
        }
        stack<T>& curStack = stackStack.top();
        curStack.pop();
        if(curStack.empty()) {
            stackStack.pop();
        }
    }

    T top(){
        return stackStack.top().top();
    }

    private:
    stack<stack<T>> stackStack;
    int capacity_;
};

int main(void) {
    SetOfStack<int> myStack(3);
    myStack.pop();
    myStack.push(0);
    myStack.pop();
    myStack.push(1); 
    myStack.push(2);
    myStack.push(3);
    cout << myStack.top() << endl;
    myStack.pop();
    myStack.pop();
    cout << myStack.top() << endl;
    return 0;
}