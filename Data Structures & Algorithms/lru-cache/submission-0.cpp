class Node {
   public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
   private:
    Node* left;
    Node* right;

    unordered_map<int, Node*> m;
    int capacity;

    // just remove the connection not delete node
    void remove(Node* node) {
        Node* nxt = node->next;
        node->prev->next = nxt;
        nxt->prev = node->prev;
    }

    void insert(Node* node) {
        Node* prv = right->prev;
        prv->next = node;
        node->prev = prv;
        node->next = right;
        right->prev = node;
    }

   public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        m.clear();
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        else {
            Node* p = m[key];
            remove(p);
            insert(p);
            return p->val;
        }
    }

    void put(int key, int value) {
        // key exist
        if (m.find(key) != m.end()) {
            Node* p = m[key];
            remove(p);
        }

        Node* p = new Node(key, value);
        insert(p);
        m[key] = p; 

        if (m.size() > capacity) {
            Node* tmp = left->next;
            remove(tmp);
            m.erase(tmp->key);
            delete tmp;
        }
    }
};

/*
A, B, C, D
0, 1, 2, 3
4, 1, 2, 3
4, 3, 6, 5

min = 1, current

*/