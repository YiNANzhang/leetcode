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
    void reorderList(ListNode *head) {
        if(head == NULL) return;
        int n = 0;
        ListNode *p = head;
        while(p != NULL) {
            p = p->next;
            n++;
        }
        int i, mid;
        mid = (n >> 1) + 1;
        vector<ListNode *> vctr;
        p = head;
        for(i = 0; i < mid; ++i) {
            p = p->next;
        }
        while(i<n){
            vctr.push_back(p);
            p = p->next;
            ++i;
        }
        p = head;
        for(i = vctr.size()-1; i >=0; --i) {
            vctr[i]->next = p->next;
            p->next = vctr[i];
            p = p->next->next;
        }
		if(n & 0x1) p->next = NULL;
		else p->next->next = NULL;
    }
};
