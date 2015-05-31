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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode *list;
        ListNode head(-1);
        //ListNode temp(-1);
        list = &head;
        for(;l1!=nullptr && l2!=nullptr;list=list->next){
            if(l1->val < l2->val){list->next = l1;l1=l1->next;}
            else{
                list->next = l2;
                l2 = l2->next;
            }
        }
        list->next = l1!=nullptr?l1:l2;
        return head.next;
    }
};
