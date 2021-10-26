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
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int last_buy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int val = prices[i];
            int tp = val - last_buy;
            if (tp > profit)
                profit = tp;
            if (val < last_buy)
                last_buy = val;
            //cout << "i=" << i << ", profit=" << profit << ", last_buy=" << last_buy << endl;
        }
        return profit;
    }
};

int main() {
    Solution s;
    vector<int> nums = {7,1,5,3,6,4};

    int output = s.maxProfit(nums);
    cout << output << endl;

    return 0;
}

