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
    
    void find_combine(vector<int> &result, vector<int> &sums, int n, int total) {
        bool found_zero = false;
        bool found_total = false;
        if (n == 2) {
            for (int i = 0; i < sums.size(); i++) {
                if (!found_zero && sums[i] == 0) {
                    found_zero = true;
                    continue;
                }
                if (!found_total && sums[i] == total) {
                    found_total = true;
                    continue;
                }
                result.push_back(sums[i]);
            }
            return;
        }
        
        int diff = sums[1] - sums[0];
        unordered_map<int, int> freq;
        vector<int> s0, s1;
        bool s0_has_zero = false;
        
        for (auto &num : sums) {
            if (freq[num]) {
                s1.push_back(num);
                freq[num]--;
            } else {
                s0.push_back(num);
                freq[num + diff]++;
                if (num == 0) s0_has_zero = true;
            }
        }
        
        if (s0_has_zero) {
            result.push_back(diff);
            find_combine(result, s0, n - 1, total - diff);
        } else {
            result.push_back(-diff);
            find_combine(result, s1, n - 1, total + diff);
        }
    }
        
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int> attr = {};
        if (n == 1) {
            if (sums[0] == 0)
                attr.push_back(sums[1]);
            else
                attr.push_back(sums[0]);

            return attr;
        }

        qsort(&sums[0], sums.size(), sizeof(int), comp);

        int total = sums[0] + sums.back();
        find_combine(attr, sums, n, total);
        return attr;
    }
};

int main() {
    Solution s;
    vector<int> sums = {-3,-2,-1,0,0,1,2,3};

    vector<int> output = s.recoverArray(3, sums);
    print_vector(output);
    cout << endl;

    return 0;
}

