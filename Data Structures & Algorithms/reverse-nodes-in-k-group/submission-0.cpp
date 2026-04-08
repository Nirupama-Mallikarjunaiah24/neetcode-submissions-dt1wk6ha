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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * dummy = new ListNode(0, head);
        ListNode * prevgroup = dummy;

        while ( true) {
            ListNode* kth = getkth(prevgroup, k);
            if ( !kth) {
                break;
            }

            ListNode * nextgroup = kth->next;

            ListNode * prev = kth->next;
            ListNode * cur = prevgroup->next; // i am flipping from the next node
            while (cur != nextgroup) {
                ListNode * next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

            ListNode * tmp = prevgroup->next;
            prevgroup->next = kth;
            prevgroup = tmp;
        }
        return dummy->next;
    }

private:

    ListNode * getkth ( ListNode * cur, int k) {

        while ( cur && k > 0) {
            k--;
            cur = cur->next;
        }

        return cur;
    }
};
