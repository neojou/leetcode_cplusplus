#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void print_vector(std::vector<T> const &v)
{
    std::cout << "[";

    for (auto it = v.begin(); it != v.end(); it++) {
	if (it != v.begin())
	    std::cout << ", ";
	std::cout << *it;
    }
    
    std::cout << "]";
}

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        /* parameter check */
        if (n <= 0)
            return {};
        
        std::vector<std::string> ret = std::vector<std::string>(n);        
        
        for (int i = 1; i <= n; i++) {
            std::string s = "";
            
            if (i % 3 == 0)
                s = "Fizz";
            if (i % 5 == 0)
                s += "Buzz";
            if (s == "")
                s = std::to_string(i);
            
            ret[i - 1] = s;
        }
        
        return ret;
    }
};

int main() {
    Solution s;

  
    std::vector<std::string> results = s.fizzBuzz(15);

    std::cout << "[";
    print_vector(results);
    std::cout << "]" << std::endl;

    return 0;
}

