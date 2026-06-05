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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minh(cmp);

        for (ListNode* list:lists) {
            minh.push(list);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (!minh.empty()) {
            ListNode* node = minh.top();
            minh.pop();
            curr->next = node;
            curr = curr->next;
            node = node->next;
            if ( node != nullptr) {
                minh.push(node);
            }
        }
        return dummy->next;
    }
};
