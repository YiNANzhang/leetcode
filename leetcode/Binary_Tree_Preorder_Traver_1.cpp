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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode *> s;
        s.push(root);
        //TreeNode *cur = root;
        while(!s.empty()) {
            TreeNode *top = s.top();
            result.push_back(top->val);
            s.pop();
            if(top->right != nullptr) s.push(top->right);
            if(top->left != nullptr) s.push(top->left);
        }
        return result;
    }
};
