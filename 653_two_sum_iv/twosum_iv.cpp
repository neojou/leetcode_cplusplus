#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void bst_to_ordered_vector(std::vector<int> &vo, TreeNode *root) {
        if (root == NULL)
            return;
        
        if (root->left)
            bst_to_ordered_vector(vo, root->left);
        
        vo.push_back(root->val);
        
        if (root->right)
            bst_to_ordered_vector(vo, root->right);
    }
    
public:
    bool check_two_sum(std::vector<int>& nums, int target) {
        int i,j;
        int size = nums.size();
        
        i = 0;
        j = size - 1;
        while (i < j) {
                int sum = nums[i] + nums[j];
                if (sum == target) {
                        return true;
                } else if (sum > target) { 
                        j--;
                } else { /* sum < target */
                        i++;
                }       
        }       
        return false;
    }   

    bool findTarget(TreeNode* root, int k) {
        std::vector<int> vo = {};
        
        bst_to_ordered_vector(vo, root);
        return check_two_sum(vo, k);
    }
};

int main() {
    Solution s;

    TreeNode *root = new TreeNode(5,
		  new TreeNode(3, new TreeNode(2), new TreeNode(4)),
		  new TreeNode(6, nullptr, new TreeNode(7)));

    std::cout << "k=9 : "
    	      << s.findTarget(root, 9)
	      << std::endl;

    std::cout << "k=28 : "
    	      << s.findTarget(root, 28)
	      << std::endl;

    return 0;
}

