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
    int maxAbsoluteSum(vector<int>& nums) {
        int curr = 0, mx = 0, mn = 0;
        for (const auto& num : nums) {
            curr += num;
            mx = max(mx, curr);
            mn = min(mn, curr);
        }
        return mx - mn;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,-5,1,-4,3,-2};

    int abs_sum = s.maxAbsoluteSum(nums);
    cout << abs_sum << endl;

    return 0;
}

