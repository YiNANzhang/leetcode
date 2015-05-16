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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p=head, *kth=head, *last;
        int n = 0;
        while(p->next != nullptr) {
            p = p->next;
            n++;
        }
        last = p;
        k = k%(n+1);
        for(int i = 0; i < n-k; ++i) {
            kth = kth->next;
        }
        last->next = dummy.next;
        dummy.next = kth->next;
        kth->next = nullptr;
        return dummy.next;
    }
};
