#include <iostream>
#include <vector>
using namespace std;

// 24分

// 空の文字列はtargetにならないという前提で書いている
int searchWord(const vector<string>& words, int left, int right, string target){
    if(left > right || words.empty()){
        return -1;
    }

    int mid = (left + right) / 2;
    int diff = 0;
    bool isLeft = true;
    int check = mid;
    while(diff * 2 < right + left){
        if(mid - diff >= left && words[mid - diff] != ""){
            check = mid - diff;
            break;
        }
        if(mid + diff < right && words[mid + diff] != ""){
            check = mid + diff;
            isLeft = false;
            break;
        }
        diff++;
    }

    int ans;
    if(words[check] == target){
        return check;
    }
    if(words[check] > target){
        ans = searchWord(words, left, mid - diff, target);
    }else if(isLeft){
        ans = searchWord(words, mid + diff, right, target);
    }else{
        ans = searchWord(words, mid + diff + 1, right, target);
    }

    return ans;
}

int main(void){
    vector<string> words = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    cout << searchWord(words, 0, words.size(), "ball") << endl;
    cout << searchWord(words, 0, words.size(), "cat") << endl;
    cout << searchWord(vector<string>(), 0, 0, "ball") << endl;
    return 0;
}