#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

class WordFreq{
public:
    WordFreq(string input) : s(input) {
        transform(s.begin(), s.end(), s.begin(), 
            [](unsigned char c) -> unsigned char { return std::tolower(c); });
    }
    double compute(string target){
        if(wordMap.find(target) != wordMap.end())
            return wordMap[target];
        stringstream ss(s);
        string word;
        double count = 0;
        double sLen = 0;
        while(getline(ss, word, ' ')){
            if(!word.empty()){
                sLen++;
                count += (word == target ? 1 : 0);
            }
        }
        double ans = count / sLen;
        wordMap.insert({target, ans});
        return ans;
    }

private:
    unordered_map<string, double> wordMap;
    string s;
};

class WordFreqMulti{
public:
    WordFreqMulti(string& input) : s(input) {
        transform(s.begin(), s.end(), s.begin(), 
            [](unsigned char c) -> unsigned char { return std::tolower(c); });
        stringstream ss(s);
        string word;
        bookSize = 0;
        while(getline(ss, word, ' ')){
            if(!word.empty()){
                bookSize++;
                if(wordMap.find(word) == wordMap.end()){
                    wordMap.insert({word, 0});
                }
                wordMap[word]++;
            }
        }
    }

    double compute(string target){
        if(wordMap.find(target) == wordMap.end())
            return 0;
        return wordMap[target] / bookSize;
    }

private:
    unordered_map<string, double> wordMap;
    string s;
    vector<string> targets;
    double bookSize;
};

int main(void){
    string s = "A new door to the unbelievable, to the possible, a new day that can always bring you anything if you have no objection to it.";
    WordFreq wf(s);
    cout << wf.compute("to") << endl;
    cout << wf.compute("a") << endl;
    WordFreqMulti wfm(s);
    cout << wfm.compute("to") << endl;
    cout << wfm.compute("a") << endl;
    return 0;
}