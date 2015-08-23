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
    ListNode *partition(ListNode *head, int x) {
        if(!head || !head->next) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy;
        while(head && head->val<x){
            p = head;
            head = head->next;
        }
        ListNode prevless(-1);
        ListNode *prevlss = &prevless;
        while(head && head->next){
            if(head->next->val<x){
                //加入节点
                prevlss->next = head->next;
                prevlss = prevlss->next;
                //删除节点
                head->next = head->next->next;
                
                prevlss->next = nullptr;
            }else{
                head = head->next;
            }
        }
        if(prevless.next){
            prevlss->next = p->next;
            p->next = prevless.next;
        }
        return dummy.next;
        
    }
};
