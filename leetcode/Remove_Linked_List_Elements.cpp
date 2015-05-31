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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy;
        while(p->next != NULL) {
            if(p->next->val == val) {
                ListNode *del = p->next;
                p->next = p->next->next;
                delete del;
            }else{
                p = p->next;
            }
        }
        return dummy.next;
    }
};
