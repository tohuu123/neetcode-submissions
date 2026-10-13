/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* p = head;
        while (p) { 
            // if (!prev) { 
            //     prev = p;
            //     p = p->next;
            //     prev->next = nullptr;
            //     continue;
            // }
            ListNode* tmp = p->next;
            p->next = prev; 
            prev = p;
            p = tmp; 
        }
        return prev; 
    }
};
