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
    int sumNumbers(TreeNode *root) {
        if(!root) return 0;
        stack<pair<TreeNode *, int> > s;
        int value = root->val;
        s.push(make_pair(root,value));
        TreeNode *cur;
        int sum = 0;
        while(!s.empty()){
            cur = s.top().first;
            value = s.top().second;
            s.pop();
            if(!cur->left && !cur->right)
                sum +=value;
            if(cur->right){int right_value=10*value+cur->right->val;s.push(make_pair(cur->right,right_value));}
            if(cur->left){int left_value=10*value+cur->left->val;s.push(make_pair(cur->left,left_value));}
        }
        return sum;
    }
};
