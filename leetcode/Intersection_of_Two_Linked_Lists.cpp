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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0, b = 0;
        ListNode *p = headA, *q= headB;
        for(;p;p = p->next, ++a);
        for(;q;q = q->next, ++b);
        p = headA; q = headB;
        while(a > b) {
            p = p->next;
            --a;
        }
        while(b > a) {
            q = q->next;
            --b;
        }
        for(; p !=nullptr && q != nullptr; p = p->next, q = q->next){
            if(p == q)
                return p;
        }
        return nullptr;
    }
};
