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
    std::vector< std::vector<int> >
    threeSum(std::vector<int>& nums, int target) {
        int i, j, k;
        int size = nums.size();
        std::vector<int> num_set(3);
        std::vector< std::vector<int> > ret = {};

        i = 0; 
        for (i = 0; i < size - 2; i++) {
            int sum = target - nums[i];
            num_set[0] = nums[i];
            
            for (j = i + 1, k = size - 1; j < k;) {
                 if(nums[j] + nums[k] == sum) {
                    num_set[1] = nums[j];
                    num_set[2] = nums[k];
                    ret.push_back(num_set);

                    while(j < k && nums[j] == nums[j+1]) 
                        j++;

                    while(j < k && nums[k] == nums[k-1])
                        k--;

		    j++; k--;
                }
                else if(nums[j] + nums[k] < sum)
                    j++;
                else 
                    k--;
            }
            
            while((i < size - 2) && (nums[i+1] == nums[i]))
                i++;
        }
                
        return ret;
    }

    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector< std::vector<int> > ret1;
        std::vector< std::vector<int> > ret = {};
        int size = nums.size();
        
        vector_qsort(nums);
        
        for (int i = 0; i < size; i++) {
            int target1 = target - nums[i];
            std::vector<int> nums3 = std::vector<int>(nums.begin() + i + 1, nums.end()); 
    
            ret1 = threeSum(nums3, target1);
            for (std::vector< std::vector<int> >::iterator it = ret1.begin(); it != ret1.end(); it++) {
                (*it).insert((*it).begin(), nums[i]);
            }
            ret.insert(ret.end(), ret1.begin(), ret1.end());
            
            while((i < size - 2) && (nums[i+1] == nums[i]))
                i++;
        }
        
        return ret;
    }

};

int main() {
    Solution s;

    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    std::vector<std::vector<int>> results = s.fourSum(nums, target);

    std::cout << "[";
    print_vector2(results);
    std::cout << "]" << std::endl;

    return 0;
}

