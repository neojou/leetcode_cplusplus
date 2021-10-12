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

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr))
            return true;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while ((fast != nullptr) && (fast->next != nullptr)) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *rev = reverseList(slow);
        return list_comp(head, rev, slow);
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1,
			new ListNode(2,
				new ListNode(2, 
					new ListNode(1))));

    bool output = s.isPalindrome(head);
    cout << ((output) ? "true" : "false")
	 << endl;

    return 0;
}

