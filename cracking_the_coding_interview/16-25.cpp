#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LruCache{
public:
    void insert(int key, int val){
        if(map.count(key) == 0) {
            if(map.size() >= maxSize){
                int del = ll.front();
                map.erase(del);
                ll.pop_front();
            }
            map.insert({key, val});
        } else {
            ll.remove(key);
            map[key] = val;
        }
        ll.push_back(key);
    }

    int get(int key){
        if(map.count(key) == 0)
            return -1;
        ll.remove(key);
        ll.push_back(key);
        return map[key];
    }

private:
    int maxSize = 3;
    unordered_map<int, int> map;
    list<int> ll;
};

int main(void){
    LruCache lru;
    lru.insert(0, 3);
    cout << lru.get(0) << endl; // 3
    lru.insert(1, 4);
    lru.insert(2, 5);
    cout << lru.get(1) << endl; // 4
    lru.insert(3, 6);
    cout << lru.get(0) << endl; // -1
    lru.insert(4, 7);
    cout << lru.get(1) << endl; // 4
    cout << lru.get(2) << endl; // -1
    return 0;
}