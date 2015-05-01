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
        stack<TreeNode *> s;
        while(root != NULL || !s.empty() ) {
            if(root) {
                s.push(root);
                root = root->left;
            } else {
                TreeNode *top = s.top();
                s.pop();
                result.push_back(top->val);
                root = top->right;
            }
        }
        return result;
    }
};
