#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++) {
            int num1 = nums[i];
            int num2 = target -nums[i];

            if (m.count(num2))
                return {m[num2], i};

            m[num1] = i;
        }
        
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

