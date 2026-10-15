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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)  
            return head;

        if (!head->next) { 
            delete head;
            return nullptr;
        }

        int length = 0;
        ListNode* p = head;
        ListNode* prev = nullptr;
        while (p) { 
            length++;
            p = p -> next;
        }
        int pos = length - n + 1;
        p = head;
        
        if (pos == 1) { 
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }

        int i = 1; 
        while (p) { 
            if (i == pos) { 
                if (prev)
                    prev->next = p->next; 
                delete p;
                break;
            }   
            prev = p;
            p = p -> next;
            i++;
        }

        return head;
    }
};
