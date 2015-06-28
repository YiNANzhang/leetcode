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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int cat = 0;
        int sum = 0;
        ListNode *res = l1;
        if(!l1 || !l2)
            return (l1==NULL)?l2:l1;
        if(l1 && l2){
        while(l1->next && l2->next){
            sum = l1->val + l2->val + cat;
            if(sum > 9){
                cat = 1;
                sum = sum - 10;
            }else{
                cat = 0;
            }
            l1->val = sum;
            l1 = l1->next;
            l2 = l2->next;
        }
        sum = l1->val + l2->val +cat;
        }
        if(l1->next == NULL && l2->next != NULL)
            l1->next = l2->next;
        if(sum > 9){
            cat = 1;
            sum = sum - 10;
        }else{
            cat = 0;
        }
        l1->val = sum;
        if(l1->next){
        l1 = l1->next;
        while(l1->next){
            sum = l1->val + cat;
            if(sum > 9){
                cat = 1;
                sum = sum - 10;
            }else{
                cat = 0;
            }
            l1->val = sum;
            l1 = l1->next;
        }
        sum = l1->val + cat;
        if(sum > 9){
            cat = 1;
            sum = sum - 10;
        }else{
            cat = 0;
        }
        l1->val = sum;
        }
        if(cat==1){
            l1->next = new ListNode(1);
        }
        return res;
    }
};
