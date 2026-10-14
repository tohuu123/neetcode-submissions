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
    void reorderList(ListNode* head) {
        // always check one node case 
        if (!head || !head->next) return;
        stack<ListNode*> st;
        ListNode* p = head;
        while (p) { 
            st.push(p);
            p = p->next;
        }
        p = head;
        while (p) { 
            ListNode* q = st.top();
            st.pop();
            ListNode* tmp = p->next;
            p->next = q;
            q->next = tmp; 
            p = tmp;
            if (p == q || p == st.top()) { 
                p->next = nullptr;
                break;
            }
        }
    }
};
