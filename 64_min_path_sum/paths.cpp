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
    int min_path_sum(vector<vector<int>>& grid, int **ms, int i, int j) {
        if (ms[i][j] != -1)
            return ms[i][j];
        
        int sum = grid[j][i];
        int wleft = INT_MAX;
        int wtop = INT_MAX;
        
        if (i >= 1)
            wleft = min_path_sum(grid, ms, i - 1, j);
        
        if (j >= 1)
            wtop = min_path_sum(grid, ms, i, j - 1);
        
        sum += (wleft < wtop) ? wleft : wtop;
        ms[i][j] = sum;
        return sum;            
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int mj = grid.size() - 1;
        int mi = grid[0].size() - 1;
        
        int **ms = (int **)malloc(sizeof(int *) * (mi + 1));
        for (int i = 0; i <= mi; i++)
            ms[i] = (int *)malloc(sizeof(int) * (mj + 1));
            
        for (int j = 0; j <= mj; j++)
            for (int i = 0; i <= mi; i++)
                ms[i][j] = -1;

        ms[0][0] = grid[0][0];
            
        return min_path_sum(grid, ms, mi, mj);        
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{1,3,1}, {1,5,1}, {4,2,1}};

    int output = s.minPathSum(grid);
    cout << output << endl;

    return 0;
}

