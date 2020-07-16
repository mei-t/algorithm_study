#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;

class WordFreq{
public:
    WordFreq(string s) : s(s) {}
    double compute(string target){
        if(wordMap.find(target) != wordMap.end())
            return wordMap[target];
        vector<string> sList;
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
        return count / sLen;
    }

private:
    unordered_map<string, double> wordMap;
    string s;
};

int main(void){
    string s = "A new door to the unbelievable, to the possible, a new day that can always bring you anything if you have no objection to it.";
    WordFreq wf(s);
    cout << wf.compute("to") << endl;
    return 0;
}