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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sz1 = 0, sz2 = 0;
        for (ListNode* p = l1; p; p=p->next)
            sz1++;
        for (ListNode* p = l2; p; p=p->next)
            sz2++;
        if (sz1 < sz2) { 
            ListNode* tmp = l1;
            l1 = l2; 
            l2 = tmp;
        }
        ListNode* head = l1; 
        int carry = 0;
        while (l1 && l2) { 
            l1->val = (l1->val + l2->val + carry);
            carry = l1->val / 10;
            l1->val%=10;
            if (!l1->next && carry > 0) {
                l1->next = new ListNode(carry);
                carry = 0; 
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (carry) { 
            l1->val = (l1->val + carry);
            carry = l1->val/10;
            l1->val %= 10;
            if (!l1->next && carry > 0) {
                l1->next = new ListNode(carry);
                break;
            }
            l1 = l1->next;
        }
        return head;
    }
};


/*
4 5 6 9 
1 2 4 
*/
