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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k==1) return head;
        ListNode d(-1);
        d.next = head;
        ListNode *dummy = &d;
        ListNode *p = head;
        int size_n=0;
        while(p){
            size_n++;
            p = p->next;
        }
        int r = size_n/k;
        int kk;
        p = head;
        while(r>0 && p->next){
            kk = 1;
            while(kk<k && p->next){
                ListNode *tmp = p->next->next;
                p->next->next = dummy->next;
                dummy->next = p->next;
                p->next = tmp;
                kk++;
            }
            r--;
            dummy = p;
            p = p->next;
        }
        return d.next;
    }
};
