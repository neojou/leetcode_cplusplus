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
void get_minmax(int &min, int &max, int a, int b, int c) {
    if (a > b) {
        min = b;
        max = a;
    } else {
        min = a;
        max = b;
    }
    if (c < min)
        min = c;
    if (c > max)
        max = c;
}

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq, l, r;
        int sz = nums.size();
        int result[sz];
        int rc = 0;
        
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
        
            if (!freq[num]++)
                l[num] = i;
            
            if (freq[num] > max) {
                max = freq[num];
                r[num] = i;
                result[0] = num;
                rc = 1;
            } else if (freq[num] == max) {
                r[num] = i;
                result[rc++] = num;
            }
        }
        
        /* please note that we should find out the shortest length */
        int minval = INT_MAX;
        for (int i = 0; i < rc; i++) {
            int x = result[i];
            minval = min(minval, r[x] - l[x] + 1);
        }
        
        return minval;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,2,3,1,4,2};

    int degree = s.findShortestSubArray(nums);
    cout << degree << endl;

    return 0;
}

