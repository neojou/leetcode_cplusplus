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
    int minCostClimbingStairs(vector<int>& cost) {
        int p2 = cost[0];
        int p1 = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int a = min(p1, p2);
            p2 = p1;
            p1 = a + cost[i];
        }
        return min(p1, p2);
    }
};

int main() {
    Solution s;
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    int output = s.minCostClimbingStairs(cost);
    cout << output << endl;

    return 0;
}

