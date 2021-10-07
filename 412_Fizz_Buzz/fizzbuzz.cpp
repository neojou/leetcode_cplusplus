#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

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
    vector<string> fizzBuzz1(int n) {
        /* parameter check */
        if (n <= 0)
            return {};
        
        vector<string> ret = vector<string>(n);        
        
        for (int i = 1; i <= n; i++) {
            string s = "";
            
            if (i % 3 == 0)
                s = "Fizz";
            if (i % 5 == 0)
                s += "Buzz";
            if (s == "")
                s = to_string(i);
            
            ret[i - 1] = s;
        }
        
        return ret;
    }

    vector<string> fizzBuzz2(int n) {
        /* parameter check */
        if (n <= 0)
            return {};
        
        vector<string> ret = vector<string>(n);
        unordered_map<int, string> m;
	m[5] = "Buzz";
	m[3] = "Fizz";
        
        for (int i = 1; i <= n; i++) {
            string s = "";
            
            for (auto iter = m.begin(); iter != m.end(); iter++)
                if (i % iter->first == 0)
                    s += iter->second;

            if (s == "")
                s = to_string(i);
            
            ret[i - 1] = s;
        }
        
        return ret;
    }

};

int main() {
    Solution s;

  
    vector<string> results = s.fizzBuzz2(15);

    cout << "[";
    print_vector(results);
    cout << "]" << endl;

    return 0;
}

