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

ListNode *list_move_to(ListNode *h, int t) {
    while (h != nullptr && --t)
        h = h->next;
    
    return h;
}

ListNode *rev_list(ListNode *h, ListNode *e) {
    ListNode *next = h->next;
    while (next != e) {
        ListNode *nn = next->next;
        next->next = h;
        h = next;
        next = nn;        
    }
    return h;
}

class Solution {
    ListNode* reverseKGroup1(ListNode *h, int k) {
        if (h == nullptr || h->next == nullptr)
            return h;
        
        ListNode *e = list_move_to(h, k);
        if (e != nullptr) {
            e = e->next;
            ListNode *nh = rev_list(h, e);            
            h->next = reverseKGroup1(e, k);
            return nh;
        } else {
            return h;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        if (k <= 1)
            return head;
        
        return reverseKGroup1(head, k);
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1,
			new ListNode(2,
			    new ListNode(3,
				new ListNode(4,
				    new ListNode(5)))));

    ListNode *output = s.reverseKGroup(head, 2);
    cout << "Output: ";
    print_ListNode(output);
    cout << endl;

    return 0;
}

