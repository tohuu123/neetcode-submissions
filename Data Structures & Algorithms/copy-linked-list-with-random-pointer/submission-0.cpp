/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        // original -> head
        unordered_map<Node*, Node*> m;
        int random_index = 0;
        Node* p = head;
        Node* dummyHead = new Node(0);
        Node* q = dummyHead;
        while (p) {
            if (!m[p]) { 
                q->next = new Node(p->val);
                m[p] = q -> next;
            }
            else { 
                q->next = m[p];
            }
            if (p->random) {
                if (m[p->random])
                    q->next->random = m[p->random];
                else {
                    q->next->random = new Node(p->random->val);
                    m[p->random] = q->next->random;
                }
            }
            q = q->next;
            p = p->next;
        }
        q = dummyHead->next;
        delete dummyHead;
        return q; 
    }
};

/*


*/
