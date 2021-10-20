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
    void permute(vector<vector<int>> &powerset, vector<int>& nums, 
                 vector<int> arr, int index) {
        powerset.push_back(arr);
        for (int i = index; i < nums.size(); i++) {
            arr.push_back(nums[i]);
            permute(powerset, nums, arr, i + 1);
            arr.pop_back();
        }
    }
    
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerset = {};
        
        permute(powerset, nums, {}, 0);
        return powerset;        
    }
};


int main() {
    Solution s;
    vector<int> nums = {1,2,3};

    vector<vector<int>> output = s.subsets(nums);
    print_vector2(output);
    cout << endl;

    return 0;
}

