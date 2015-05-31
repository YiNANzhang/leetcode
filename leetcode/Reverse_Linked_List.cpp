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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = head;
        while(p->next != nullptr) {
            ListNode *q = p->next;
            p->next = p->next->next;
            q->next = dummy.next;
            dummy.next = q;
        }
        return dummy.next;
    }
};
