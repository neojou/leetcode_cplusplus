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

/* TreeNode */
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
private:
    vector<vector<int>> &levelOrder1(vector<vector<int>> &vvi, TreeNode* root, int level) {
        if (root == nullptr)
            return vvi;

        vector<int> vi;
        if (level >= vvi.size()) {
            vi = {root->val};
            vvi.push_back(vi);
        } else {
            vi = vvi[level];
            vi.push_back(root->val);
            vvi[level] = vi;
        }
        
        if (root->left)
            levelOrder1(vvi, root->left, level + 1);
        
        if (root->right)
            levelOrder1(vvi, root->right, level + 1);
        
        return vvi;
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vvi = {};
        
        if (root == nullptr)
            return vvi;

        vector<int> vi = {root->val};
        vvi.push_back(vi);
        
        if (root->left)
            levelOrder1(vvi, root->left, 1);
        
        if (root->right)
            levelOrder1(vvi, root->right, 1);
        
        return vvi;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(3,
			new TreeNode(9),
			new TreeNode(20,
				new TreeNode(15),
				new TreeNode(7)));

    vector<vector<int>> output = s.levelOrder(root);
    cout << "Output: ";
    print_vector2(output);

    return 0;
}

