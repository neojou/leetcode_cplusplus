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
public:
    int tribonacci(int n) {
        if (n == 0 || n == 1)
            return n;
        if (n == 2)
            return 1;
        
        int t0 = 0, t1 = 1, t2 = 1;
        int t;
        for (int i = 3; i <= n; i++) {
            t = t2;
            t2 = t2 + t1 + t0;
            t0 = t1;
            t1 = t;
        }
        return t2;
    }
};

int main() {
    Solution s;

    int output = s.tribonacci(37);
    cout << output << endl;

    return 0;
}

