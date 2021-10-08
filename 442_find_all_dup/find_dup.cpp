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

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size(); 
        vector<int> ret = {};
        
        if (size < 2)
                return {};
        
        for (int i = 0; i < size; i++) {
            int idx = i;
            while (nums[idx] != idx + 1) {
                if (nums[idx] == nums[nums[idx] - 1]) break;
                swap(nums[idx], nums[nums[idx] - 1]);
            }
        }
        
        for (int i = 0; i < size; i++)
            if (nums[i] != i + 1)
                ret.push_back(nums[i]);
    
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    vector<int> ret = s.findDuplicates(nums);
    print_vector(ret);
    cout << endl;

    return 0;
}

