#include <iostream>
#include <vector>
using namespace std;
#define SIZE 26

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