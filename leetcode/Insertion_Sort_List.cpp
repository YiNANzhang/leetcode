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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *nodecur, *nodecmp;
        int temp;
        nodecur = head;
        nodecmp = NULL;
        while(nodecur){
            nodecmp = head;
            while(nodecmp != nodecur){
                if(nodecmp->val > nodecur->val){
                    temp = nodecmp->val;
                    nodecmp->val = nodecur->val;
                    nodecur->val = temp;
                }
                nodecmp = nodecmp->next;
            }
            nodecur = nodecur->next;
        }
        return head;
    }
};
