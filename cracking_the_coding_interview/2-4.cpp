#include <iostream>
#include <list>
using namespace std;

list<int> splitList(list<int>& linkedList, int x){
    auto i = linkedList.begin();
    auto lastUnchecked = linkedList.end();
    lastUnchecked--;
    while(i != lastUnchecked){
        cout << *i << " " << *lastUnchecked << endl;
        if(*i >= x){
            swap(i, lastUnchecked);
            lastUnchecked--;
        }else{
            i++;
        }
    }
    return linkedList;
}

int main(void){
    list<int> input {3, 5, 8, 5, 10, 2, 1};
    list<int> output = splitList(input, 5);
    for(auto it = output.begin(); it!=output.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}