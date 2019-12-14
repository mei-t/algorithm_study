#include <iostream>
#include <vector>
using namespace std;

int findKthMulti(size_t k){
    vector<int> v(1, 1);
    size_t threeIndex = 0;
    size_t fiveIndex = 0;
    size_t sevenIndex = 0;
    while(v.size() < k){
        int threeNext = v[threeIndex] * 3;
        int fiveNext = v[fiveIndex] * 5;
        int sevenNext = v[sevenIndex] * 7;
        if(threeNext < fiveNext && threeNext < sevenNext){
            if(threeNext != v[v.size() - 1]){
                v.push_back(threeNext);
            }
            threeIndex++;
        }else if(fiveNext < sevenNext){
            if(fiveNext != v[v.size() - 1]){
                v.push_back(fiveNext);
            }
            fiveIndex++;
        }else{
            if(sevenNext != v[v.size() - 1]){
                v.push_back(sevenNext);
            }
            sevenIndex++;
        }
    }
    return v[k - 1];
}

int main(void){
    cout << findKthMulti(5) << endl; // 9
    cout << findKthMulti(6) << endl; // 15
    cout << findKthMulti(7) << endl; // 21
    cout << findKthMulti(8) << endl; // 25
    cout << findKthMulti(9) << endl; // 27
    cout << findKthMulti(10) << endl; // 35
    cout << findKthMulti(11) << endl; // 45
    return 0;
}