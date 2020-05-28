#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity): capacity(capacity) {}
    
    int get(int key) {
        if(hashMap.find(key) == hashMap.end()){
            return -1;
        }
        numList.remove(key);
        numList.push_back(key);
        return hashMap[key];
    }
    
    void put(int key, int value) {
        if(hashMap.find(key) != hashMap.end()){
            hashMap[key] = value;
            numList.remove(key);
            numList.push_back(key);
            return;
        }
        if(hashMap.size() == capacity){
            int deleteKey = numList.front();
            numList.pop_front();
            hashMap.erase(deleteKey);
        }
        numList.push_back(key);
        hashMap.insert({key, value});
    }

private:
    int capacity;
    unordered_map<int, int> hashMap;
    list<int> numList;
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
    cout << cache.get(2) << endl; // 2
    cache.put(3, 3);
    cout << cache.get(1) << endl; // -1
    cout << cache.get(2) << endl; // 2
    cache.put(4, 4);
    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // -1
    cout << cache.get(4) << endl; // 4
    return 0;
}