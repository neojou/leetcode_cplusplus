#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        
        for (auto i = 0; i < nums.size(); i++)
            if (m.count(target - nums[i]))
                return {m[target - nums[i]], i};
            else
                m[nums[i]] = i;
        
        return {};
    }
};

int main() {
    Solution s;

    std::vector<int> nums = {2,7,11,15};
    std::vector<int> results = s.twoSum(nums, 9);

    std::cout << "[";
    for (std::vector<int>::iterator it = results.begin(); it != results.end(); ++it) {
	if (it != results.begin())
	    std::cout << ", ";
	std::cout << *it;
    }
    std::cout << "]" << std::endl;

    return 0;
}

