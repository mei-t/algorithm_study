#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class TrieNode {
public:
    TrieNode() : next(vector<unique_ptr<TrieNode>>(26, nullptr)), isEnd(false) {}
    vector<unique_ptr<TrieNode>> next;
    bool isEnd;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root(make_unique<TrieNode>()) {}
    
    /** Inserts a word into the trie. */
    bool insert(const string& word) {
        if(!validInput(word))
            return false;

        TrieNode* node = root.get();
        for(size_t i = 0; i < word.size(); i++){
            if(!(node->next[index(word, i)]))
                node->next[index(word, i)] = make_unique<TrieNode>();
            node = node->next[index(word, i)].get();
        }
        node->isEnd = true;
        return true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word) {
        pair<bool, TrieNode*> triePair = searchPrefix(word);
        if(!triePair.first)
            return false;
        return triePair.second->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) {
        return searchPrefix(prefix).first;
    }

private:
    unique_ptr<TrieNode> root;

    int index(string s, int i){
        return s[i] - 'a';
    }

    pair<bool, TrieNode*> searchPrefix(const string& prefix){
        TrieNode* node = root.get();
        for(size_t i = 0; i < prefix.size(); i++){
            TrieNode* nextNode = node->next[index(prefix, i)].get();
            if(!nextNode)
                return pair<bool, TrieNode*>(false, nullptr);
            node = nextNode;
        }
        return pair<bool, TrieNode*>(true, node);
    }

    bool validInput(const string& word){
        for(char c: word){
            if(c <'a' && c > 'z')
                return false;
        }
        return true;
    }
};

int main(void){
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl; // true
    cout << trie.search("app") << endl; // false
    cout << trie.startsWith("app") << endl; // true
    trie.insert("app");
    cout << trie.search("app") << endl; // true
    return 0;
}