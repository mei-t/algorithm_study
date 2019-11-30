#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define SIZE 26

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if(memo.count(s)){
            return memo[s];
        }
        
        vector<string> result;
        if(wordDict.count(s)){
            result.push_back(s);
        }
        
        for(int i=0; i<s.size(); i++){
            string word = s.substr(i);
            if(wordDict.count(word)){
                string res = s.substr(0, i);
                vector<string> prev = combine(word, wordBreak(res, wordDict));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        memo.insert({s, result});
        return result;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return wordBreak(s, wordSet);
    }
    
    vector<string> combine(string word, vector<string> prev){
        for(string& s: prev){
            s += ' ' + word;
        }
        return prev;
    }

private:
    unordered_map<string, vector<string>> memo;
};

// trieを使って解く問題かと思ったけど、メモリを使いすぎたみたい。なんで？
// trieのspace complexityはどれくらい？
class Solution {
public:
    struct Trie{
        Trie* children[SIZE];
        bool isEndOfWord;
    };

    Trie* getTrie(){
        Trie* newTrie = new Trie;
        for(int i=0; i<SIZE; i++){
            newTrie->children[i] = nullptr;
        }
        newTrie->isEndOfWord = false;
        return newTrie;
    }

    void insert(Trie* root, string key){
        Trie* current = root;
        for(char c: key){
            if(!current->children[c - 'a']){
                current->children[c - 'a'] = getTrie();
            }
            current = current->children[c -'a'];
        }
        current->isEndOfWord = true;
    }

    Trie* find(Trie* trie, char c){
        return trie->children[c - 'a'];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root = getTrie();
        for(const string& word: wordDict){
            insert(root, word);
        }

        vector<string> ans;
        vector<int> spaceIndex;
        findNewString(s, 0, find(root, s[0]), spaceIndex, ans);

        return ans;
    }

    void findNewString(const string& s, int i, Trie* trie, vector<int>& spaceIndexs, vector<string>& ans){
        if(!trie){
            return;
        }
        
        if(i == s.size() - 1){
            if(trie->isEndOfWord){
                string ansS ="";
                int prev = 0;
                for(int spaceIndex: spaceIndexs){
                    ansS += s.substr(prev, spaceIndex - prev) + " ";
                    prev = spaceIndex;
                }
                ansS += s.substr(prev);
                ans.push_back(ansS);
            }
            return;
        }
        
        vector<int> copySpaceIndexs(spaceIndexs);
        findNewString(s, i+1, find(trie, s[i+1]), copySpaceIndexs, ans);
        if(trie->isEndOfWord){
            spaceIndexs.push_back(i+1);
            findNewString(s, i+1, find(root, s[i+1]), spaceIndexs, ans);
        }
    }

private:
    Trie* root;
};

int main(void){
    return 0;
}