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
        
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        ListNode* a = l1;
        ListNode* b = l2;
        int carry = 0;
        while ( a != nullptr || b != nullptr || carry != 0) {
            
            int v1 = ( a != nullptr) ? a->val : 0;
            int v2 = (b != nullptr)? b->val : 0;

            int val = v1 + v2 + carry;
            carry = val/10;
            cur->next = new ListNode(val%10);

            cur = cur->next;
             a = (a != nullptr) ? a->next : nullptr; // to avoid segmentation fault
             b = (b != nullptr) ? b->next : nullptr;

        }    
        ListNode* res = dummy->next;

        delete dummy;
        return res;
 
    
    }
};
