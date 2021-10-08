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
        ListNode *prev, *cur;
        int val;
        
        if (head == nullptr)
            return head;
        
        prev = head;
        cur = head->next;
        
        val = prev->val;
        while (cur != nullptr) {
            if (val == cur->val) {
                prev->next = cur->next;
            } else {
                val = cur->val;
                prev = cur;
            }               
            cur = cur->next;
        }
        
        return head;
    }
};

int main() {
    Solution s;

    ListNode *head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
   
    ListNode *ret = s.deleteDuplicates(head);
    print_ListNode(ret);
    cout << endl;

    return 0;
}

