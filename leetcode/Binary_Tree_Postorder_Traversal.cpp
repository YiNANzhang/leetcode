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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *prev, *cur = root;
        prev = nullptr;
        //if(root != nullptr) s.push(root);
        do {
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }
            prev = nullptr;
            while(!s.empty()) {
                cur = s.top();
                if(cur->right == prev) {
                    result.push_back(cur->val);
                    s.pop();
                    prev = cur;
                } else {
                    cur = cur->right;
                    break;
                }
            }
        } while(!s.empty());
        return result;
    }
};
