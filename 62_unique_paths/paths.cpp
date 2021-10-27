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
    int combine_cal(int i, int j) {
        long long c, a;
        c = i + j;
        a = (j > i) ? i : j;
        
        long long result = c;
        for (int b = 2; b <= a; b++) {
            result *= (--c);
            result /= b;
        }
        return result;
    }
    
public:
    int uniquePaths(int m, int n) {
        if (m == 1)
            return 1;
        if (n == 1)
            return 1;
        
        return combine_cal(m - 1, n - 1);        
    }
};

int main() {
    Solution s;

    int output = s.uniquePaths(3, 7);
    cout << output << endl;

    return 0;
}

