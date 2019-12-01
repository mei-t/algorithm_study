#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define SIZE 26

// https://leetcode.com/problems/word-search-ii/

#define SIZE 26

class Trie{
public:
    Trie();
    void insert(string key);
    Trie* find(char key) const;
    bool isInAns;
    const string& getWord() const;

private:
    Trie* children[SIZE];
    string word; // wordの最後以外は空文字列
};

Trie::Trie(){
    for(int i=0; i<SIZE; i++){
        children[i] = nullptr;
    }
    word = "";
    isInAns = false;
}

void Trie::insert(string key){
    Trie* current = this;
    for(int i=0; i<key.size(); i++){
        int index = key[i] - 'a';
        if(!current->children[index]){
            current->children[index] = new Trie(); // Trie trie; でstack領域に確保も可能
        }
        current = current->children[index];
    }
    current->word = key;
}

Trie* Trie::find(char key) const {
    return this->children[key - 'a'];
}

const string& Trie::getWord() const {
    return this->word;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if(board.empty() || words.empty()){
            return ans;
        }
        
        Trie* root = new Trie();
        for(const string& word: words){
            root->insert(word);
        }
        
        vector<bool> row(board[0].size(), false);
        vector<vector<bool>> visited;
        for(int i=0; i<board.size(); i++){
            visited.push_back(row);
        }
        
        for (int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                Trie* trie = root->find(board[i][j]);
                if(trie){
                    vector<vector<bool>> visitedCopy(visited);
                    findWord(board, i, j, trie, visitedCopy, ans);
                }
            }
        }
        return ans;
    }

    void findWord(const vector<vector<char>>&board, int i, int j, Trie* trie, vector<vector<bool>>& visited, vector<string>& ans){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j]){
            return;
        }
        
        trie = trie->find(board[i][j]);
        if(!trie){
            return;
        }

        if(trie->getWord() != "" && !trie->isInAns){
            ans.push_back(trie->getWord());
            trie->isInAns = true;
        }

        visited[i][j] = true;
        findWord(board, i-1, j, trie, visited, ans);
        findWord(board, i, j-1, trie, visited, ans);
        findWord(board, i+1, j, trie, visited, ans);
        findWord(board, i, j+1, trie, visited, ans);
        visited[i][j] = false;
    }
};

int main(void){
    return 0;
}