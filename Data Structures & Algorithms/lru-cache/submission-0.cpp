class Node {
public:
     int key;
     int val;
     Node* prev;
     Node* next;

     Node (int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
     }
};




class LRUCache {
private:
    int cap;
    unordered_map<int,Node*> cache;
    Node* head; // dummy variables to keep track
    Node* tail; // dummy vaiables to keep track

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next-> prev = prev;
    }

    void insert( Node* node) {
        Node* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
        // using tail to keep all recent ones
        // inserting at the tail
    }


public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;

    }
    
    int get(int key) {
        if ( cache.find(key) != cache.end()){
            // insert it to the beginning again because it was used
            Node* node = cache[key]; // the node
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if ( cache.find(key) != cache.end()) {
            remove(cache[key]); //change and bring it to top again
        }
        Node * node = new Node(key,value);
        cache[key] = node;
        insert(node);

        if ( cache.size() > cap) {
            Node * rem = head->next;
            remove(rem);
            cache.erase(rem->key);
            delete rem;
        }
    }
};
