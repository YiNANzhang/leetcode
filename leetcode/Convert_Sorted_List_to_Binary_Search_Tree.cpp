/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        //TreeNode * root;
        //if(head == NULL) return NULL;
        return buildBST(head);
    }
    
    TreeNode * buildBST(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->right = buildBST(slow->next); 
        if(head == slow);
        else {
            fast = head;
            while(fast->next != slow) fast = fast->next;
            fast->next = NULL;
            root->left = buildBST(head);
        }
        return root;
    }
};
