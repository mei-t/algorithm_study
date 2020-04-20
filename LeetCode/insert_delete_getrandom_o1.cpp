#include <iostream>
#include <unordered_map>
#include <random>
#include <vector>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(valMap.find(val) != valMap.end()){
            return false;
        }
        valMap.insert({val, nums.size()});
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(valMap.find(val) == valMap.end()){
            return false;
        }
        int last = nums.back();
        nums[valMap[val]] = last;
        nums.pop_back();
        valMap[last] = valMap[val];
        valMap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        // mt19937 gen(rd());
        // uniform_int_distribution<> dis(0, valMap.size() - 1);
        // auto itr = nums.begin();
        // return *(itr + dis(gen));
        return nums[rand() % nums.size()];
    }

private:
    unordered_map<int, int> valMap;
    vector<int> nums;
    // random_device rd;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(void){
    return 0;
}