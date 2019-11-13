#include <iostream>
#include <set>
#include <vector>
#include <utility>
using namespace std;

class RobotRoute{
public:
    RobotRoute(int r, int c, set<pair<int, int>> noEntry){
        r_ = r;
        c_ = c;
        noEntry_ = noEntry;
    }

    vector<pair<int, int> > findRoute(){
        findRoute(0,0);
        return route;
    }

    void findRoute(int i, int j){
        if(i == r_-1 && j == c_-1){
            return;
        }

        if(i < r_-1 && noEntry_.find(make_pair(i + 1, j)) == noEntry_.end()){
            route.push_back(make_pair(i, j));
            findRoute(i+1, j);
        }else if(j < c_-1 && noEntry_.find(make_pair(i, j + 1)) == noEntry_.end()){
            route.push_back(make_pair(i, j));
            findRoute(i, j+1);
        }else{
            noEntry_.insert(make_pair(i, j));
            route.clear();
            findRoute(0, 0);
        }
    }

private:
    set<pair<int, int>> noEntry_;
    vector<pair<int, int> > route;
    int r_;
    int c_;
};

int main(void){
    return 0;
}