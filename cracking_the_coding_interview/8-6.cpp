#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class TowerOfHanoi{
public:
    TowerOfHanoi(int num){
        for(int i=0; i<num; i++){
            stack1.push(i);
        }
    }

    void start(){
        cout << "start" << endl;
        if(stack1.empty()){
            return;
        }
        cout << stack1.size() << endl;
        move(1, 3 - (stack1.size() % 2));
        cout << "start" << endl;
        while(!stack1.empty() || !stack2.empty()){
            cout << "aaa" << endl;
            // int empty = getEmpty();
            checkState();
            if(empty != -1){
                move(max, empty);
            }else{
                move(min, mid);
            }
        }
        return;
    }

    void move(int i, int j){
        cout << "move" << endl;
        if(stackMap[i].empty() || (!stackMap[j].empty() && stackMap[i].top() > stackMap[j].top())){
            cout << "move failed" << endl;
            return;
        }
        cout << "Move " << stackMap[i].top() << " from " << i << " to " << j << "." << endl;
        stackMap[j].push(stackMap[i].top());
        stackMap[i].pop();
        return;
    }
    
    void checkState(){
        empty = -1;
        max = -1;
        mid = -1;
        min = -1;
        if(stack1.empty()){
            empty = 1;
            max = stack2.top() > stack3.top() ? 2 : 3;
            return;
        }else if(stack2.empty()){
            empty = 2;
            max = stack1.top() > stack3.top() ? 1 : 3;
            return;
        }else if(stack3.empty()){
            empty = 3;
            max = stack1.top() > stack2.top() ? 1 : 2;
            return;
        }
        int tmp = stack1.top() > stack2.top() ? 1 : 2;
        min = stackMap[tmp].top() > stack3.top() ? tmp : 3;
        if(tmp == min){
            mid = tmp;
            return;
        }
        tmp = tmp == 1 ? 2 : 1;
        mid = stackMap[tmp].top() < stack3.top() ? tmp : 3;
        return;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
    stack<int> stack3;
    int empty, max, min, mid;
    unordered_map<int, stack<int>> stackMap = {
        { 1, stack1 },
        { 2, stack2 },
        { 3, stack3 }};
};

int main(void){
    cout << "aaaaaaaaa" << endl;
    cout << "main start" << endl;
    TowerOfHanoi hanoi1(3);
    hanoi1.start();
    cout << "Hanoi1 finished." << endl;
    TowerOfHanoi hanoi2(10);
    hanoi2.start();
    cout << "Hanoi2 finished." << endl;
    return 0;
}