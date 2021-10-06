#include <iostream>
#include <vector>
#include <algorithm>

void print_vector(std::vector<int> const &v)
{
    std::cout << "[";

    for (auto it = v.begin(); it != v.end(); it++) {
	if (it != v.begin())
	    std::cout << ", ";
	std::cout << *it;
    }
    
    std::cout << "]";
}

void print_vector2(std::vector<std::vector<int>> const &v)
{
    std::cout << "[";

    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin())
            std::cout << ", ";
	print_vector(*it);
    }
    
    std::cout << "]";
}

int compare(const void *a, const void *b)
{
    return (*((int *)a) - *((int *)b));
}

void vector_qsort(std::vector<int> &v)
{
    qsort(&v[0], v.size(), sizeof(int), compare);
}


class Solution {
public:    
    std::vector<int>
    twoSum(std::vector<int>& nums, int target) {
        int i,j;
        int size = nums.size();

        i = 0;
        j = size - 1;
        while (i < j) {
                int sum = nums[i] + nums[j];
                if (sum == target) {
                        return {i + 1, j + 1};
                } else if (sum > target) {
                        j--;
                } else { /* sum < target */
                        i++;
                }
        }
        return {};             
    }
};

int main() {
    Solution s;

    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> results = s.twoSum(nums, target);

    print_vector(results);
    std::cout << std::endl;

    return 0;
}

