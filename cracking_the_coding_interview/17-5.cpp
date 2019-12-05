#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_map>
using namespace std;

// 32分34秒

pair<int, int> shrinkString(size_t left, size_t right, const string& s, char more, int diff, unordered_map<string, pair<int, int>>* memo){
    if(left > right){
        return make_pair(0, 0);
    }
    string numString = to_string(left) + to_string(right);
    if(memo->count(numString)){
        return (*memo)[numString];
    }

    while(diff > 0){
        if(s[left] == more){
            left++;
            diff--;
        }else if(s[right] == more){
            right--;
            diff--;
        }else{
            break;
        }
    }
    if(diff == 0){
        return make_pair(left, right - left + 1);
    }
    auto leftMove = shrinkString(left + 1, right, s, more, diff+1, memo);
    auto rightMove = shrinkString(left, right - 1, s, more, diff+1, memo);
    auto ans = leftMove.second > rightMove.second ? leftMove : rightMove;
    numString = to_string(left) + to_string(right);
    memo->insert({numString, ans});
    return ans;
}

string sameLenSubStr(string s){
    int diff = 0;
    string copy = s;
    for(int i=0; i<copy.size(); i++){
        if(copy[i] <= '9'){
            copy[i] = 'A';
            diff++;
        }else{
            copy[i] = 'B';
            diff--;
        }
    }
    if(diff == 0){
        return s;
    }
    char more = diff > 0 ? 'A' : 'B';
    diff = abs(diff);
    unordered_map<string, pair<int, int>> memo;
    auto pair = shrinkString(0, copy.size()-1, copy, more, diff, &memo);
    return s.substr(pair.first, pair.second);
}

// 最適解
string sameLenSubStr2(string s){
    int numStrDiff = 0;
    vector<int> diff;
    for(int i=0; i<s.size(); i++){
        if(s[i] <= '9'){
            numStrDiff++;
        }else{
            numStrDiff--;
        }
        diff.push_back(numStrDiff);
    }

    unordered_map<int, int> firstPlace;
    pair<int, int> ansSlice = make_pair(0, 0);
    firstPlace.insert({0, -1});
    for(int i=0; i<diff.size(); i++){
        if(firstPlace.find(diff[i]) != firstPlace.end()){
            int len = i - firstPlace[diff[i]];
            if(ansSlice.second < len){
                ansSlice = make_pair(firstPlace[diff[i]] + 1, len);
            }
        }else{
            firstPlace.insert({diff[i], i});
        }
    }
    return s.substr(ansSlice.first, ansSlice.second);
}

int main(void){
    string s1 = "a39gj4l20";
    cout << s1 << endl;
    cout << sameLenSubStr(s1) << endl;
    cout << sameLenSubStr2(s1) << endl;
    cout << endl;
    string s2 = "a39hjkrgj4l20";
    cout << s2 << endl;
    cout << sameLenSubStr(s2) << endl;
    cout << sameLenSubStr2(s2) << endl;
    cout << endl;
    string s3 = "a39gj4l209872895e";
    cout << s3 << endl;
    cout << sameLenSubStr(s3) << endl;
    cout << sameLenSubStr2(s3) << endl;
    return 0;
}