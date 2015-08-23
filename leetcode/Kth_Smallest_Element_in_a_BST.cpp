/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        int t = calculateNode(root->left);
        if (t == k-1) return root->val;
        if (t+1 < k) return kthSmallest(root->right, k-t-1);
        else return kthSmallest(root->left, k);
    }
    
    int calculateNode(TreeNode * root) {
        if (!root) return 0;
        return 1 + calculateNode(root->left) + calculateNode(root->right);
    }
};
