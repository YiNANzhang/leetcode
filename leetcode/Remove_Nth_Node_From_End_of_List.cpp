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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int i;
	//	ListNode *dnode = head;
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *l = dummy;
		ListNode *pre = dummy;
		for (i=0;i<n;i++){
			l = l->next;
		}
		while(l->next){
			l = l->next;
			pre = pre->next;
		}
		ListNode *dnode = pre->next;
		pre->next = pre->next->next;
		delete dnode;
		return dummy->next;
    }
};
