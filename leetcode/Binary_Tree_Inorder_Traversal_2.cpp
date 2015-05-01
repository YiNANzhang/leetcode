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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *cur = root;
        while(cur != NULL) {
            if(cur->left == NULL) {
                result.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode *node = cur->left;
                while(node->right != NULL && node->right != cur)
                    node = node->right;
                if(node->right == NULL) {
                    node->right = cur;
                    cur = cur->left;
                } else {
                    result.push_back(cur->val);
                    node->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
