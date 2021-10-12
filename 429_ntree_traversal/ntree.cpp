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

/* N-ary Tree Node */
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
private:
    vector<vector<int>> &levelOrder1(vector<vector<int>> &vvi, Node* root, int level) {
        if (root == nullptr)
            return vvi;

        if (level >= vvi.size()) {
            vector<int> vi = {root->val};
            vvi.push_back(vi);
        } else {
            vector<int> &vi = vvi[level];
            vi.push_back(root->val);
        }

        for (int i = 0; i < root->children.size(); i++)
            levelOrder1(vvi, root->children[i], level + 1);

        return vvi;
    }

public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vvi = {};
        
        if (root == nullptr)
            return vvi;
        
        vector<int> vi = {root->val};
        vvi.push_back(vi);
        
        for (int i = 0; i < root->children.size(); i++)
            levelOrder1(vvi, root->children[i], 1);
        
        return vvi;
    }
};

int main() {
    Solution s;
    Node *root = new Node(1, {
			new Node(3, {new Node(5), new Node(6)}),
			new Node(2),
			new Node(4)});

    vector<vector<int>> output = s.levelOrder(root);
    cout << "Output: ";
    print_vector2(output);

    return 0;
}

