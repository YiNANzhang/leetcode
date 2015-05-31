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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m == n) return head;
        ListNode *first = new ListNode(-1);
        ListNode *p = head;
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        dummy.next = p;
        int k;
        for(k=1;k<m;k++){
            p = p->next;
            prev = prev->next;
        }
        ListNode *end = p;
        while(k<=n){
            ListNode *tmp = p;
            p = p->next;
            tmp->next = first->next;
            first->next = tmp;
            k++;
        }
        prev->next = first->next;
        end->next = p;
        delete first;
        head = prev->next;
        return dummy.next;
    }
};
