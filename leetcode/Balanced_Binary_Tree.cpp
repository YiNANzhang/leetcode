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
    bool isBalanced(TreeNode *root) {
        return Height(root) >= 0;
    }
    
    int Height(TreeNode *root) {
        if(root == nullptr) return 0;
        int left = Height(root->left);
        int right = Height(root->right);
        if(left == -1 || right == -1 || abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
};
