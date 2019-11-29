#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define SIZE 26

// https://leetcode.com/problems/word-search-ii/

#define SIZE 26

struct Trie{
    Trie* children[SIZE];
    string word; // wordの最後以外は空文字列
    bool isInAns;
};

Trie* getTrie(){
    Trie* newTrie = new Trie;
    for(int i=0; i<SIZE; i++){
        newTrie->children[i] = nullptr;
    }
    newTrie->word = "";
    newTrie->isInAns = false;
    return newTrie;
}

void insert(Trie* root, string key){
    Trie* current = root;
    for(int i=0; i<key.size(); i++){
        int index = key[i] - 'a';
        if(!current->children[index]){
            current->children[index] = getTrie();
        }
        current = current->children[index];
    }
    current->word = key;
}

Trie* find(Trie* current, char key){
    return current->children[key - 'a'];
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if(board.empty() || words.empty()){
            return ans;
        }
        
        Trie* root = getTrie();
        for(const string& word: words){
            insert(root, word);
        }
        
        vector<bool> row(board[0].size(), false);
        vector<vector<bool>> visited;
        for(int i=0; i<board.size(); i++){
            visited.push_back(row);
        }
        
        for (int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                Trie* trie = find(root, board[i][j]);
                if(trie){
                    vector<vector<bool>> visitedCopy(visited);
                    findWord(board, i, j, trie, visitedCopy, ans);
                }
            }
        }
        return ans;
    }

    void findWord(const vector<vector<char>>&board, int i, int j, Trie* trie, vector<vector<bool>>& visited, vector<string>& ans){
        if(!trie){
            return;
        }
        if(trie->word != "" && !trie->isInAns){
            ans.push_back(trie->word);
            trie->isInAns = true;
        }

        visited[i][j] = true;
        if(i-1 >= 0 && !visited[i-1][j]){
            findWord(board, i-1, j, find(trie, board[i-1][j]), visited, ans);
        }
        if(j-1 >= 0 && !visited[i][j-1]){
            findWord(board, i, j-1, find(trie, board[i][j-1]), visited, ans);
        }
        if(i+1 < board.size() && !visited[i+1][j]){
            findWord(board, i+1, j, find(trie, board[i+1][j]), visited, ans);
        }
        if(j+1 < board[0].size() && !visited[i][j+1]){
            findWord(board, i, j+1, find(trie, board[i][j+1]), visited, ans);
        }
        visited[i][j] = false;
    }
};

int main(void){
    return 0;
}