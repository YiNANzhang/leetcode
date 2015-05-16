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
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> cur;
        queue<TreeNode *> pre;
        vector<int>     ret;
        
        if(root) pre.push(root);
        while(!pre.empty()){
            ret.push_back(pre.back()->val);    
            while(!pre.empty()) {
                if(pre.front()->left) {
                    cur.push(pre.front()->left);
                }
                if(pre.front()->right) {
                    cur.push(pre.front()->right);
                }
                pre.pop();
            }
            while(!cur.empty()){
                pre.push(cur.front());
                cur.pop();
            }
        }
        return ret;
    }
};
