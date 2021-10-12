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

class Solution {
public:
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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        struct ListNode *cur = head;
        struct ListNode *prev = nullptr, *next = nullptr;
        struct ListNode *mpre = nullptr, *mcur = nullptr;
        bool rev = false;
        int pos = 0;
        
        while (cur != nullptr) {
            next = cur->next;
            
            if (pos == left - 1) {
                mpre = prev;
                mcur = cur;
                rev = true;
            }
            
            if (rev)
                cur->next = prev;
            
            if (pos == right - 1) {
                if (mpre)
                    mpre->next = cur;
                else
                    head = cur;
                
                if (mcur)
                    mcur->next = next;
                
                rev = false;
            }
        
            prev = cur;
            cur = next;
            pos++;
        }

        return head;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1,
			new ListNode(2,
				new ListNode(3, 
					new ListNode(4,
						new ListNode(5)))));

    ListNode *rev = s.reverseBetween(head, 2, 4);
    print_ListNode(rev);
    cout << endl;

    return 0;
}

