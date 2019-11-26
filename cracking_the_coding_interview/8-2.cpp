#include <iostream>
#include <set>
#include <vector>
#include <utility>
using namespace std;

// routeを返す
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
            route.push_back(make_pair(i, j));
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

// route数を返す
class RobotRoute2 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0][0]){
            return 0;
        }
        obstacleGrid[0][0] = 1;
        for(int i=1; i<obstacleGrid[0].size(); i++){
            if(!obstacleGrid[0][i] && obstacleGrid[0][i-1]){
                obstacleGrid[0][i] = 1;
            }else{
                obstacleGrid[0][i] = 0;
            }
        }
        
        for(int i=1; i<obstacleGrid.size(); i++){
            if(!obstacleGrid[i][0] && obstacleGrid[i-1][0]){
                obstacleGrid[i][0] = 1;
            }else{
                obstacleGrid[i][0] = 0;
            }
        }
        
        for(int i=1; i<obstacleGrid.size(); i++){
            for(int j=1; j<obstacleGrid[0].size(); j++){
                if(!obstacleGrid[i][j]){
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }else{
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};

int main(void){
    set<pair<int, int>> obstacleSet = {make_pair(2, 0), make_pair(2, 1), make_pair(1, 3)};
    RobotRoute route1(3, 5,obstacleSet);
    vector<pair<int, int> > result = route1.findRoute();
    for(auto pair: result){
        cout << pair.first << " " << pair.second << endl;
    }
    vector<vector<int>> grid ={
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    RobotRoute2 route2;
    cout << route2.uniquePathsWithObstacles(grid) << endl;
    return 0;
}