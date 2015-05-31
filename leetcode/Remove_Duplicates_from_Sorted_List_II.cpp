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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *cur = head;
        ListNode *pro = head->next;
        while(pro){
            if(cur->val == pro->val){
                while(pro && cur->val == pro->val){
                    cur->next = pro->next;
                    pro = cur->next;
                }
                pre->next = cur->next;
                if(!cur->next) return dummy.next;
                cur = cur->next;
                pro = cur->next;
            }else{
                pre = pre->next;
                cur = cur->next;
                pro = pro->next;
            }
        }
        return dummy.next;
    }
};
