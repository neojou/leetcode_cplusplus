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
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        int result, curr;
        result = curr = nums[0];

        for (int i = 1;i < sz; i++) {
            int x = nums[i];
            curr = max(curr + x, x);
            result = max(result, curr);
        }
        
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    int output = s.maxSubArray(nums);
    cout << output << endl;

    return 0;
}

