#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

struct NIInfo {
    int pos;
    vector<NestedInteger> nestedList;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) : nestedList(nestedList) {
        s.push({0, nestedList});
    }
    
    int next() {
        return nestedInteger.getInteger();
    }
    
    bool hasNext() {
        while(s.top().pos >= s.top().nestedList.size() && s.size() > 1)
            s.pop();
        if(s.size() == 1 && s.top().pos >= s.top().nestedList.size())
            return false;
        nestedInteger = s.top().nestedList[s.top().pos];
        s.top().pos++;
        while(!nestedInteger.isInteger()){
            vector<NestedInteger> newList = nestedInteger.getList();
            if(!newList.empty()){
                nestedInteger = newList[0];
                s.push({1, newList});
                continue;
            }
            s.top().pos++;
            if(s.top().pos >= s.top().nestedList.size())
                return false;
            nestedInteger = s.top().nestedList[s.top().pos];
        }
        cout << "aa" << endl;
        return true;
    }
private:
    vector<NestedInteger> nestedList;
    stack<NIInfo> s;
    NestedInteger nestedInteger;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(void){
    return 0;
}