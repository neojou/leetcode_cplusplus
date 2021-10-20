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
    static int comp(const void *a, const void *b) {
        return *((int *)a) - *((int *)b);
    }
    
    void permute(vector<vector<int>> &powerset, vector<int>& nums, 
                 vector<int> arr, int index) {
        powerset.push_back(arr);
        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i - 1])
                continue;
            arr.push_back(nums[i]);
            permute(powerset, nums, arr, i + 1);
            arr.pop_back();
        }
    }
    
public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        qsort(&nums[0], nums.size(), sizeof(int), comp);
        
        vector<vector<int>> powerset = {};
        
        permute(powerset, nums, {}, 0);
        return powerset;        
    }
};


int main() {
    Solution s;
    vector<int> nums = {1,2,2};

    vector<vector<int>> output = s.subsetsWithDup(nums);
    print_vector2(output);
    cout << endl;

    return 0;
}

