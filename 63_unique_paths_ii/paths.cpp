#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

template <typename T>
void print_vector(vector<T> const &v)
{
    cout << "[";

    for (auto it = v.begin(); it != v.end(); it++) {
	if (it != v.begin())
	    cout << ", ";
	cout << *it;
    }
    
    cout << "]";
}

template <typename T>
void print_vector2(vector<vector<T>> const &v)
{
    cout << "[";

    for (auto it = v.begin(); it != v.end(); it++) {
	if (it != v.begin())
	    cout << ", ";
	print_vector(*it);
    }
    
    cout << "]" << endl;
}

class Solution {
    int cal_paths(vector<vector<int>>& og, int** cal, int i, int j) {
      /*cout << "i=" << i << ", j=" << j << endl;
        if (i < 0)
            return 0;
        if (j < 0)
            return 0;
        */

        if (og[j][i] == 1)
            return 0;
        
        if (cal[i][j] != -1)
            return cal[i][j];
        
        if (i == 0) {
            return cal_paths(og, cal, i, j - 1);
        }
        if (j == 0) {
            return cal_paths(og, cal, i - 1, j);           
        }
        
        cal[i][j] = cal_paths(og, cal, i - 1, j) + cal_paths(og, cal, i, j - 1);
        return cal[i][j];
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int j;
        int mj = obstacleGrid.size();
        int i;
        int mi = obstacleGrid[0].size();
        
        //cout << "mi=" << mi << ", mj=" << mj << endl;
        int **cal;
        cal = (int **)malloc(sizeof(int *) * mi);
        for (i = 0; i < mi; i++)
            cal[i] = (int *)malloc(sizeof(int) * mj);
        
        for (j = 0; j < mj; j++)
            for (i = 0; i < mi; i++)
                cal[i][j] = -1;
        
        cal[0][0] = !obstacleGrid[0][0]; 
        return cal_paths(obstacleGrid, cal, mi - 1, mj - 1);
    }
};


int main() {
    Solution s;
    vector<vector<int>> obstacleGrid = {{0,0,0}, {0,1,0}, {0,0,0}};

    int output = s.uniquePathsWithObstacles(obstacleGrid);
    cout << output << endl;

    return 0;
}

