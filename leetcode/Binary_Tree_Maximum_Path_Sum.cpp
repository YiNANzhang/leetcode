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
    int max_sum;
public:
    int maxPathSum(TreeNode *root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }
    int dfs(TreeNode *root) {
        if(root == NULL) return 0;
        int cur_val = root->val;
        int l, r;
        l = dfs(root->left);
        r = dfs(root->right);
        //if(l > 0) cur_val += l;
        //if(r > 0) cur_val += r;
        cur_val = max(cur_val, max(cur_val + r, cur_val + l));
        max_sum = max(max_sum, max(cur_val, root->val + l + r));
        return cur_val;
    }
};
