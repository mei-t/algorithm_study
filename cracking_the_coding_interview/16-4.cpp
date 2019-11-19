#include <iostream>
#include <vector>
using namespace std;

bool isWin(const vector<string>& result, char target){
    int size = result.size();
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(result[i][j] != target){
                break;
            }
            if(j == size - 1){
                return true;
            }
        }
        for(int j=0; j<size; j++){
            if(result[j][i] != target){
                break;
            }
            if(j == size - 1){
                return true;
            }
        }
    }

    for(int i=0; i<size; i++){
        if(result[i][i] != target){
            break;
        }
        if(i == size - 1){
            return true;
        }
    }

    for(int i=0; i<size; i++){
        if(result[i][size-i-1] != target){
            break;
        }
        if(i == size - 1){
            return true;
        }
    }
    return false;
}

int judge(const vector<string>& result){
    if(isWin(result, '1')){
        return 1;
    }else if(isWin(result, '0')){
        return 0;
    }
    return -1;
}

int main(void){
    vector<string> result = {
        "010",
        "110",
        "011"
    };
    cout << judge(result) << endl;
    return 0;
}