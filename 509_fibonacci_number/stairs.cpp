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
    int fib(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        
        long long a=0, b=1;
        long long t;
        while(n--) {
            t = b;
            b = b + a;
            a = t;
        }
        return a;        
    }
};

int main() {
    Solution s;

    int output = s.fib(30);
    cout << output << endl;

    return 0;
}

