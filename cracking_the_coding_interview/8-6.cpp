#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class TowerOfHanoi{
public:
    TowerOfHanoi(int num){
        for(int i=num; i>0; i--){
            stacks[0].push(i);
        }
    }

    void start(){
        cout << "start" << endl;
        if(stacks[0].empty()){
            return;
        }
        cout << "top is " << stacks[0].top() << endl;
        cout << stacks[0].size() << endl;
        move(0, 2 - (stacks[0].size() % 2));
        cout << "start" << endl;
        while(!stacks[0].empty() || !stacks[1].empty()){
            cout << "aaa" << endl;
            // int empty = getEmpty();
            checkState();
            if(empty != -1){
                cout << max << ", " << empty << endl;
                move(max, empty);
            }else{
                cout << "bbb" << endl;
                move(min, mid);
            }
        }
        return;
    }

    void move(int i, int j){
        cout << "move" << endl;
        if(stacks[i].empty() || (!stacks[j].empty() && stacks[i].top() > stacks[j].top())){
            cout << "move failed" << endl;
            return;
        }
        cout << "stack[0].size() = " << stacks[0].size() << endl;
        cout << "stack[1].size() = " << stacks[1].size() << endl;
        cout << "stack[2].size() = " << stacks[2].size() << endl;
        cout << "Move " << stacks[i].top() << " from " << i << " to " << j << "." << endl;
        stacks[j].push(stacks[i].top());
        stacks[i].pop();
        return;
    }
    
    void checkState(){
        empty = -1;
        max = -1;
        mid = -1;
        min = -1;
        
        stack<int>& stack1 = stacks[0];
        stack<int>& stack2 = stacks[1];
        stack<int>& stack3 = stacks[2];

        cout << "stack1.size() = " << stack1.size() << endl;
        cout << "stack2.size() = " << stack2.size() << endl;
        cout << "stack3.size() = " << stack3.size() << endl;
        cout << stack1.empty() << " " << stack2.empty() << " " << stack3.empty() << endl;

        // if(stack1.empty()){
        //     cout << "stack1 is empty" << endl;
        //     empty = 0;
        //     max = stack2.top() > stack3.top() ? 1 : 2;
        //     return;
        // }else 
        if(stack2.empty()){
            cout << "stack2 is empty" << endl;
            empty = 1;
            max = stack1.top() > stack3.top() ? 0 : 2;
            return;
        }else if(stack3.empty()){
            cout << "stack3 is empty" << endl;
            empty = 2;
            max = stack1.top() > stack2.top() ? 0 : 1;
            return;
        }
        int tmp = stack1.top() < stack2.top() ? 0 : 1;
        min = stacks[tmp].top() < stack3.top() ? tmp : 2;
        if(tmp != min){
            mid = tmp;
            return;
        }
        tmp = tmp == 0 ? 1 : 0;
        mid = stacks[tmp].top() < stack3.top() ? tmp : 2;
        return;
    }

private:
    int empty, max, min, mid;
    
    static constexpr size_t NB_STACKS = 3;
    stack<int> stacks[NB_STACKS];
};

class Hanoi2{
public:
    Hanoi2(int k);
    void start();
    void moveToDisk(stack<int>* origin, stack<int>* buffer, stack<int>* disk, size_t i);
    void moveTop(stack<int>* origin, stack<int>* disk);
    void finish();
private:
    stack<int> origin;
    stack<int> buffer;
    stack<int> disk;
};

Hanoi2::Hanoi2(int k){
    for(int i = k; i > 0; i--){
        origin.push(i);
    }
}
void Hanoi2::start(){
    moveToDisk(&origin, &buffer, &disk, origin.size());
    finish();
}

void Hanoi2::moveToDisk(stack<int>* origin, stack<int>* buffer, stack<int>* disk, size_t i){
    if(i == 0){
        return;
    }
    moveToDisk(origin, disk, buffer, i - 1);
    moveTop(origin, disk);
    moveToDisk(buffer, origin, disk, i - 1);
}

void Hanoi2::moveTop(stack<int>* origin, stack<int>* disk){
    disk->push(origin->top());
    origin->pop();
    return;
}

void Hanoi2::finish(){
    while(!disk.empty()){
        cout << disk.top() << " ";
        disk.pop();
    }
    cout << endl;
    return;
}

int main(void){
    // cout << "aaaaaaaaa" << endl;
    // cout << "main start" << endl;
    // TowerOfHanoi hanoi1(3);
    // hanoi1.start();
    // cout << "Hanoi1 finished." << endl;
    // TowerOfHanoi hanoi2(10);
    // hanoi2.start();
    // cout << "Hanoi2 finished." << endl;

    Hanoi2 hanoi1(3);
    hanoi1.start();

    Hanoi2 hanoi2(10);
    hanoi2.start();

    return 0;
}