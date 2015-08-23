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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return nullptr;
        //if (p->val > q->val) swap(p->val, q->val);
        if ((root->val - p->val) * (root->val - q->val) <= 0) return root;
        else if (root->val < p->val) return lowestCommonAncestor(root->right, p, q);
        else 
            return lowestCommonAncestor(root->left, p, q);
    }
};
