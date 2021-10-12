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
    vector<int> &preorderTraversal1(vector<int> &vi, TreeNode *root) {
        if (root == nullptr)
            return vi;

        vi.push_back(root->val);
        
        if (root->left)
            preorderTraversal1(vi, root->left);
                
        if (root->right)
            preorderTraversal1(vi, root->right);
        
        return vi;
    }

    vector<int> &inorderTraversal1(vector<int> &vi, TreeNode *root) {
        if (root == nullptr)
            return vi;

        if (root->left)
            inorderTraversal1(vi, root->left);

        vi.push_back(root->val);
                
        if (root->right)
            inorderTraversal1(vi, root->right);
        
        return vi;
    }

    vector<int> &preorder1(vector<int> &vi, Node* root) {
        if (root == nullptr)
            return vi;
        
        vi.push_back(root->val);
        
        for (int i = 0; i < root->children.size(); i++)
            preorder1(vi, root->children[i]);
        
        return vi;
    }

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

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        
        if (val > root->val)
                root->right = insertIntoBST(root->right, val);
        else if (val < root->val)
                root->left = insertIntoBST(root->left, val);
        
        return root;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vi = {};
        
        if (root == nullptr)
            return vi;
        
        vi = preorderTraversal1(vi, root);
        return vi;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vi = {};
        
        if (root == nullptr)
            return vi;
        
        vi = inorderTraversal1(vi, root);
        return vi;        
    }

    vector<int> preorder(Node* root) {
        vector<int> vi = {};
        
        if (root == nullptr)
            return vi;
        
        vi = preorder1(vi, root);
        
        return vi;
    }
};

int main() {
    Solution s;
    Node *root = new Node(1, {
			new Node(3, {new Node(5), new Node(6)}),
			new Node(2),
			new Node(4)});

    vector<int> output = s.preorder(root);
    cout << "Output: ";
    print_vector(output);

    return 0;
}

