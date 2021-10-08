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
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int count = 1;
        bool twice = false;
        
        for (int i = 1; i < size; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[count++] = nums[i];
                twice = false;
            } else if (!twice) {
                nums[count++] = nums[i];
                twice = true;                
            }
        }
        
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};

    int k = s.removeDuplicates(nums);
    vector<int> ret(nums.begin(), nums.begin() + k);
    print_vector(ret);
    cout << endl;

    return 0;
}

