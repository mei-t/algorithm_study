#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define SIZE 26

unordered_map<int, vector<char>> numMap = {
    {0, {}},
    {1, {}},
    {2, {'a', 'b', 'c'}},
    {3, {'d', 'e', 'f'}},
    {4, {'g', 'h', 'i'}},
    {5, {'j', 'k', 'l'}},
    {6, {'m', 'n', 'o'}},
    {7, {'p', 'q', 'r', 's'}},
    {8, {'t', 'u', 'v'}},
    {9, {'w', 'x', 'y', 'z'}}
};

class Trie{
public:
    Trie();
    void insert(string s);
    Trie* find(char c) const;
    const string& getWord() const;
private:
    Trie* children[SIZE];
    string word;
};

Trie::Trie(){
    for(int i=0; i<SIZE; i++){
        children[i] = nullptr;
    }
    word = "";
}

void Trie::insert(string s){
    Trie* current = this;
    for(int i = 0; i < s.size(); i++){
        if(!find(s[i])){
            current->children[s[i] - 'a'] = new Trie();
        }
        current = current->children[s[i] - 'a'];
    }
    current->word = s;
}

Trie* Trie::find(char c) const{
    return this->children[c - 'a'];
}

const string& Trie::getWord() const{
    return this->word;
}

void findMatchWord(Trie* trie, const vector<int>& nums, size_t i, vector<string>* res){
    if(i == 0){
        if(trie->getWord() != ""){
            res->push_back(trie->getWord());
        }
        return;
    }

    for(char c: numMap[nums[i - 1]]){
        if(trie->find(c)){
            findMatchWord(trie->find(c), nums, i-1, res);
        }
    }
}

vector<string> findMatchWord(int num, const vector<string>& words){
    vector<int> nums;
    while(num > 0){
        nums.push_back(num % 10);
        num /= 10;
    }

    Trie* root = new Trie();
    for(string word: words){
        if(word.size() == nums.size()){
            root->insert(word);
        }
    }

    vector<string> res;
    findMatchWord(root, nums, nums.size(), &res);
    return res;
}

int main(void){
    vector<string> words = {"used", "at", "tree", "use", "take"}; // "wait"を含めるとなぜかsegmentation faultになる
    vector<string> res = findMatchWord(8733, words);
    for(string s: res){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}