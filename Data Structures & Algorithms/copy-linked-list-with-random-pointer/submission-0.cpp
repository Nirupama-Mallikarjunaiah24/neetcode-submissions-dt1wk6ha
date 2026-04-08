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
        unordered_map <Node*, Node*> oldtonew;
        oldtonew[NULL] = NULL;
        Node* cur = head;
        while ( cur != nullptr) {
            Node* newnode = new Node(cur->val);
            oldtonew[cur] = newnode;
            cur = cur->next;
        }
        cur = head;
        while ( cur != nullptr ) {
            Node * pttonew = oldtonew[cur];
            pttonew->next = oldtonew[cur->next];
            pttonew->random = oldtonew[cur->random];
            cur = cur->next;
        }

        return oldtonew[head];
        
    }
};
