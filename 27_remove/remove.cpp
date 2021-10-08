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
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int count = 0;
        
        for (int i = 0; i < size; i++) {
            if (nums[i] == val)
                continue;
            nums[count++] = nums[i];
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int k = s.removeElement(nums, val);
    vector<int> ret(nums.begin(), nums.begin() + k);
    print_vector(ret);
    cout << endl;

    return 0;
}

