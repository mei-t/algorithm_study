#include <iostream>
#include <stack>
using namespace std;

// 14分10秒
template <typename T>
class MyQueue {
public:
    MyQueue(){}

    void push(T a){
        while(!queueStack.empty()){
            preStack.push(queueStack.top());
            queueStack.pop();
        }
        queueStack.push(a);
        while(!preStack.empty()){
            queueStack.push(preStack.top());
            preStack.pop();
        }
    }

    void pop(){
        queueStack.pop();
    }

    T front(){
        return queueStack.top();
    }

    bool empty(){
        return queueStack.empty();
    }

private:
    stack<T> preStack;
    stack<T> queueStack;
};

int main(void){
    MyQueue<int> myQueue;
    myQueue.push(0);
    myQueue.push(1);
    myQueue.push(2);
    myQueue.pop();
    myQueue.push(3);
    while(!myQueue.empty()){
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;
    return 0;
}