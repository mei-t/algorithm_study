#include <iostream>
using namespace std;

// 29分56秒

bool patternMatch(string aWord, string bWord, const string& sentence, const string& pattern, size_t sI, size_t pI, size_t bLen){
    if(sI == sentence.size()){
        if(pI != pattern.size()){
            return false;
        }
        return true;
    }

    if(bWord == "" && pattern[pI] != pattern[0]){
        bWord = sentence.substr(sI, bLen);
    }
    string word = pattern[pI] == pattern[0] ? aWord: bWord;
    if(sentence.substr(sI, word.size()) != word){
        return false;
    }
    return patternMatch(aWord, bWord, sentence, pattern, sI + word.size(), pI + 1, bLen);
}

bool patternMatch(const string& sentence, const string& pattern){
    if(pattern.empty()){
        return sentence.empty();
    }
    int aCount = 0;
    for(int i = 0; i < pattern.size(); i++){
        if(pattern[i] == pattern[0]){
            aCount++;
        }
    }

    int bCount = pattern.size() - aCount;
    int maxLen = (sentence.size() - bCount) / aCount;
    for(int i = maxLen; i > 0; i--){
        if((sentence.size() - aCount * i) % bCount == 0){
            int bLen = (sentence.size() - aCount * i) / bCount;
            string word = sentence.substr(0, i);
            bool isMatch = patternMatch(word, "", sentence, pattern, 0, 0, bLen);
            if(isMatch){
                return true;
            }
        }
    }
    return false;
}

int main(void){
    string sentence = "catcatgocatgo";
    string pattern = "aabab";
    bool isMatch = patternMatch(sentence, pattern);
    cout << isMatch << endl;
    return 0;
}