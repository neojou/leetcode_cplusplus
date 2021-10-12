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

/* ListNode */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_ListNode(ListNode* h)
{
    cout << "[";

    if (h != nullptr) {
        cout << h->val;

    	for (ListNode *it = h->next; it != nullptr; it = it->next)
	    cout << " ," << it->val;
    }
    
    cout << "]";
}

bool list_comp(ListNode *l1, ListNode *l2, ListNode *end) {
    while (l1 != end) {
        if (l1->val != l2->val)
            return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return true;
}

ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *next;
        
        while (head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
}

/* BST */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string &print_TreeNode1(string &s, TreeNode* t)
{
    if (t == nullptr)
        return s;

    s += to_string(t->val);
    s += ", ";

    if (t->left)
	print_TreeNode1(s, t->left);

    if (t->right)
	print_TreeNode1(s, t->right);

    return s;
}
 
void print_TreeNode(TreeNode* t)
{
    cout << "[";
    string s = "";
    s = print_TreeNode1(s, t);
    cout << s.substr(0, s.size() - 2) << "]" << endl;
}

class Solution {
public:
    TreeNode* searchBST1(TreeNode* root, int val) {
        TreeNode *ret;
        
        if (root == nullptr)
            return nullptr;
        
        if (root->val == val)
            return root;
        else if (root->val < val)
            return searchBST1(root->right, val);
        else
            return searchBST1(root->left, val);
    }

    TreeNode* searchBST2(TreeNode* root, int val) {
        while (root) {
            if (root->val == val)
                return root;
            else if (root->val < val)
                root = root->right;
            else
                root = root->left;
        }
        return root;
    }


};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(4,
			new TreeNode(2,
				new TreeNode(1), 
				new TreeNode(3)),
			new TreeNode(7));
    int val = 2;

    cout << "Input: ";
    print_TreeNode(root);

    TreeNode *output = s.searchBST1(root, val);
    cout << "Output: ";
    print_TreeNode(output);

    output = s.searchBST2(root, val);
    cout << "Output: ";
    print_TreeNode(output);

    return 0;
}

