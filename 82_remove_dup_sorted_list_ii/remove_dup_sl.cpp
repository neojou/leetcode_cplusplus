#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr))
            return head;

        /* If the first value is different to the second one,
         * then keep the first one and do from the next.
         */ 
        int val = head->val;
        ListNode *cur = head->next;
        if (val != cur->val) {
            head->next = deleteDuplicates(cur);
            return head;
        }

        /* Otherwise, take off these elements, 
         * and then check from the next new element
         */ 
        cur = cur->next;
        while ((cur != nullptr) && (cur->val == val))
            cur = cur->next;
        
        return deleteDuplicates(cur);
    }
};

int main() {
    Solution s;

    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5)))))));
   
    ListNode *ret = s.deleteDuplicates(head);
    print_ListNode(ret);
    cout << endl;

    return 0;
}

