#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if(board.empty() || words.empty()){
            return ans;
        }
        
        unordered_map<char, vector<string>> charMap;
        for(const string& word: words){
            if(charMap.find(word[0]) == charMap.end()){
                charMap.insert({word[0], vector<string>()});
            }
            charMap[word[0]].push_back(word);
        }
        
        vector<bool> row(board[0].size(), false);
        vector<vector<bool>> visited;
        for(int i=0; i<board.size(); i++){
            visited.push_back(row);
        }
        
        for (int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                // if(charMap.find(board[i][j]) != charMap.end() && !charMap[board[i][j]].empty()){
                if(charMap.find(board[i][j]) != charMap.end()){
                    for(auto itr = charMap[board[i][j]].begin(); itr != charMap[board[i][j]].end(); ){
                        cout << *itr << endl;
                        vector<vector<bool>> visitedCopy(visited);
                        if(findWord(board, *itr, i, j, 0, visitedCopy)){
                            ans.push_back(*itr);
                            charMap[board[i][j]].erase(itr);
                        }else{
                            itr++;
                        }
                    }
                }
            }
        }
        return ans;
    }
    
    bool findWord(const vector<vector<char>>& board, const string& word, int i, int j, int num, vector<vector<bool>>& visited){
        cout << i << " " << j << endl;
        if(num == word.size() - 1 && board[i][j] == word[num]){
            cout << "cc" << endl;
            return true;
        }
        if(board[i][j] != word[num]){
            cout << board[i][j] << " " << word[num] << endl;
            cout << "dddddddddd" << endl;
            return false;
        }
        
        visited[i][j] = true;
        bool isLeft = false;
        bool isUp = false;
        bool isRight = false;
        bool isDown = false;
        if(i-1 >= 0 && !visited[i-1][j]){
            isLeft = findWord(board, word, i-1, j, num + 1, visited);
        }
        // cout << "left finish" << endl;
        
        if(j-1 >= 0 && !visited[i][j-1] && !isLeft){
            isUp = findWord(board, word, i, j-1, num + 1, visited);
        }
        // cout << "up finish" << endl;
        if(i+1 < board.size() && !visited[i+1][j] && !isLeft && !isUp){
            isRight = findWord(board, word, i+1, j, num + 1, visited);
        }
        // cout << "right finish" << endl;
        if(j+1 < board[0].size() && !visited[i][j+1] && !isLeft && !isUp && !isRight){
            isDown = findWord(board, word, i, j+1, num + 1, visited);
        }
        // cout << "down finish" << endl;
        
        return isLeft || isUp || isRight || isDown;
    }
};

int main(void){
    return 0;
}