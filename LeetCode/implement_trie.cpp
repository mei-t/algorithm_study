#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode() : next(vector<TrieNode*>(26, nullptr)), isEnd(false) {}
    vector<TrieNode*> next;
    bool isEnd;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()) {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!(node->next[index(word, i)]))
                node->next[index(word, i)] = new TrieNode();
            node = node->next[index(word, i)];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        pair<bool, TrieNode*> triePair = searchPrefix(word);
        if(!triePair.first)
            return false;
        return triePair.second->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchPrefix(prefix).first;
    }

private:
    TrieNode* root;

    int index(string s, int i){
        return s[i] - 'a';
    }

    pair<bool, TrieNode*> searchPrefix(string prefix){
        TrieNode* node = root;
        for(int i = 0; i < prefix.size(); i++){
            TrieNode* nextNode = node->next[index(prefix, i)];
            if(!nextNode)
                return pair<bool, TrieNode*>(false, nullptr);
            node = nextNode;
        }
        return pair<bool, TrieNode*>(true, node);
    }
};

int main(void){
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl; // true
    cout << trie->search("app") << endl; // false
    cout << trie->startsWith("app") << endl; // true
    trie->insert("app");
    cout << trie->search("app") << endl; // true
    return 0;
}