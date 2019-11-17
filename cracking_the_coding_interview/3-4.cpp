#include <iostream>
#include <stack>
using namespace std;

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

    T top(){
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
        cout << myQueue.top() << " ";
        myQueue.pop();
    }
    cout << endl;
    return 0;
}