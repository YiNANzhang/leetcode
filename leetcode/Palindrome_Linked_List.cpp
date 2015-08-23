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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode *p = head;
        int listLen = 0;
        while (p != NULL) { listLen++; p = p->next; }
        ListNode *fp = head;
        int i = 0;
        //ListNode dummy(-1);
        //dummy.next = head;
        ListNode *pre = NULL;
        ListNode *bp = head;
        while (i++ < listLen/2) {
            fp = fp->next;
            bp->next = pre;
            pre = bp;
            bp = fp;
        }
        bp = pre;
        pre = fp;
        if (listLen & 0x1) fp = fp->next;
        while (fp != NULL) {
            if (fp->val != bp->val) return false;
            ListNode *tmp = bp;
            bp = bp->next;
            tmp->next = pre;
            pre = tmp;
            fp = fp->next;
        }
        return true;
    }
};
