#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int A, B;
    cin >> A >> B;
    vector<int> com_divis; // common divisors
    for(int i = 2; i < min(A, B); i++){
        if((A % i == 0) && (B % i == 0)){
            com_divis.push_back(i);
        }
    } 
    vector<int> disjoints;
    for(int cm : com_divis){
        bool isDisjoint = true;
        for(int disjoint: disjoints){
            if(cm % disjoint == 0){
                isDisjoint = false;
                break;
            }
        }
        if(isDisjoint){
            disjoints.push_back(cm);
        }
    }
    disjoints.push_back(1);
    cout << disjoints.size() << endl;
    return 0;
}