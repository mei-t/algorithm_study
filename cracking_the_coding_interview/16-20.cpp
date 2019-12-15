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

// 最適解
class MatchWord{
public:
    MatchWord(const vector<string>& words);
    vector<string> findMatchWord2(int num);
private:
    unordered_map<char, int> charMap;
    unordered_map<int, vector<string>> matchMap;
};

MatchWord::MatchWord(const vector<string>& words){
    unordered_map<char, int> charMap;
    for(auto it : numMap){
        for(auto it2: it.second){
            charMap[it2] = it.first;
        }
    }

    for(string word: words){
        int num = 0;
        for(int i = 0; i< word.size(); i++){
            if(i > 0){
                num *= 10;
            }
            num += charMap[word[i]];
        }
        if(matchMap.find(num) == matchMap.end()){
            matchMap.insert({num, vector<string>()});
        }
        matchMap[num].push_back(word);
    }
}
vector<string> MatchWord::findMatchWord2(int num){
    return matchMap[num];
}

int main(void){
    vector<string> words = {"used", "at", "tree", "use", "take"};
    vector<string> res = findMatchWord(8733, words); // wordsに"wait"を含めるとなぜかsegmentation faultになる
    for(string s: res){
        cout << s << " ";
    }
    cout << endl;

    MatchWord matchword(words);
    vector<string> res2 = matchword.findMatchWord2(8733);
    for(string s: res2){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}