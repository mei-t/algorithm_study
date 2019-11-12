#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
using namespace std;

class RobotRoute{
public:
    RobotRoute(int r, int c, unordered_set<pair<int, int>> noEntry){
        r_ = r;
        c_ = c;
        noEntry_ = noEntry;
    }

    vector<pair<int, int> > findRoute(){
        findRoute(0,0);
        return route;
    }

    void findRoute(int i, int j){
        if(i == r-1 && j == c-1){
            return;
        }

        if(i < r-1 && noEntry.find(make_pair(i + 1, j)) == noEntry.end()){
            route.push_back(make_pair(i, j));
            findRoute(i+1, j);
        }else if(j < c-1 && noEntry.find(make_pair(i, j + 1)) == noEntry.end()){
            route.push_back(make_pair(i, j));
            findRoute(i, j+1);
        }else{
            noEntry.insert(make_pair(i, j));
            route.clear();
            findRoute(0, 0);
        }
    }

private:
    unordered_set<pair<int, int>> noEntry_;
    vector<pair<int, int> > route;
    int r_;
    int c_;
};

int main(void){
    return 0;
}