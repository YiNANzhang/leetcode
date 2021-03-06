/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *p = head;
        while(p && p->next){
            p->val = (p->val)^(p->next->val);
            p->next->val = (p->val) ^(p->next->val);
            p->val = (p->val)^(p->next->val);
            p = p->next;
            p = p->next;
        }
        return head;
    }
};
