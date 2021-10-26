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
void get_minmax(int &min, int &max, int a, int b, int c) {
    if (a > b) {
        min = b;
        max = a;
    } else {
        min = a;
        max = b;
    }
    if (c < min)
        min = c;
    if (c > max)
        max = c;
}

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        int result = INT_MIN;
        int curr_min = 1, curr_max = 1;
        for (const auto& x : nums) {
            if (x == 0)
                curr_min = curr_max = 0;
            else
                get_minmax(curr_min, curr_max, x, curr_min * x, curr_max * x);
            
            result = max(result, curr_max);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,3,-2,4};

    int output = s.maxProduct(nums);
    cout << output << endl;

    return 0;
}

