#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if(hashMap.find(key) == hashMap.end()){
            return -1;
        }
        cout << hashMap[key] << endl;
        return hashMap[key];
    }
    
    void put(int key, int value) {
        if(hashMap.find(key) != hashMap.end()){
            return;
        }
        if(hashMap.size() == _capacity){
            int deleteKey = q.front();
            q.pop();
            hashMap.erase(deleteKey);
        }
        q.push(key);
        hashMap.insert({key, value});
    }

private:
    int _capacity;
    unordered_map<int, int> hashMap;
    queue<int> q;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(void){
    LRUCache cache(2);
    cout << cache.get(1) << endl; // -1
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 1
    cache.put(3, 3);
    cout << cache.get(1) << endl; // -1
    cout << cache.get(2) << endl; // 2
    return 0;
}