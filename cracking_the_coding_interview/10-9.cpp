#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> searchLines(vector<vector<int>>& matrix, int target, int m_min, int m_max, int n_min, int n_max);
pair<int, int> searchRows(vector<vector<int>>& matrix, int target, int m_min, int m_max, int n_min, int n_max);

int searchLine(vector<vector<int>>& matrix, int target, int m, int n_min, int n_max){
    int n_left = n_min;
    int n_right = n_max;
    int res;
    // cout << "left = " << n_left << ", right = " << n_right << ", target = " << target << endl;
    while(1){
        int n_mid = (n_left + n_right) / 2;
        // cout << "left = " << n_left << ", mid = " << n_mid << ", right = " << n_right << endl;
        if(matrix[m][n_mid] == target){
            res = n_mid;
            break;
        }else if(matrix[m][n_mid] < target){
            if(n_max <= n_mid + 1 || matrix[m][n_mid + 1] > target){
                res = n_mid;
                break;
            }
            n_left = n_mid - 1;
        }else if(matrix[m][n_mid] > target){
            // if(n_min == n_mid || matrix[m][n_mid - 1] < target){
            if(n_min == n_mid){
                res = n_mid;
                break;
            }
            n_right = n_mid;
        }
    }
    return res;
}

int searchRow(vector<vector<int>>& matrix, int target, int m_min, int m_max, int n){
    int m_left = m_min;
    int m_right = m_max;
    int res;
    cout << "left = " << m_left << ", right = " << m_right << endl;
    while(1){
        int m_mid = (m_left + m_right) / 2;
        if(matrix[m_mid][n] == target){
            res = m_mid;
            break;
        }else if(matrix[m_mid][n] < target){
            if(m_max <= m_mid + 1 || matrix[m_mid + 1][n] > target){
                res = m_mid;
                break;
            }
            m_left = m_mid - 1;
        }else if(matrix[m_mid][n] > target){
            // if(m_min == m_mid || matrix[m_mid - 1][n] < target){
            if(m_min == m_mid){
                res = m_mid;
                break;
            }
            m_right = m_mid;
        }
    }
    return res;
}

pair<int, int> searchLines(vector<vector<int>>& matrix, int target, int m_min, int m_max, int n_min, int n_max){
    int n = searchLine(matrix, target, m_min, n_min, n_max);
    cout << "n = " << n << endl;
    if(matrix[m_min][n] == target)
        return pair<int, int>(m_min, n);
    return searchRows(matrix, target, m_min + 1, m_max, n_min, n);
}

pair<int, int> searchRows(vector<vector<int>>& matrix, int target, int m_min, int m_max, int n_min, int n_max){
    cout << n_min << endl;
    cout << "m : " << m_min << ", " << m_max << endl;
    cout << "n_min = " << n_min << endl;
    int m = searchRow(matrix, target, m_min, m_max, n_min);
    if(matrix[m][n_min] == target)
        return pair<int, int>(m, n_min);
    return searchLines(matrix, target, m_min, m, n_min + 1, n_max);
}

// Return pair(-1, -1) if the element doesn't find.
pair<int, int> searchElement(vector<vector<int>>& matrix, int target){
    if(matrix.empty()){
        return pair<int, int>(-1, -1);
    }
    return searchLines(matrix, target, 0, matrix.size(), 0, matrix[0].size());
}

int main(void){
    vector<vector<int>> matrix = {
        {0, 1, 6, 8, 15},
        {2, 3, 9, 13, 16},
        {4, 5, 14, 35, 36}
    };
    cout << "aa" << endl;
    pair<int, int> res = searchElement(matrix, 9);
    cout << res.first << " " << res.second << endl;
    // int ans = searchLine(matrix, 9, 0, 0, matrix[0].size());
    // cout << ans << endl;
    return 0;
}