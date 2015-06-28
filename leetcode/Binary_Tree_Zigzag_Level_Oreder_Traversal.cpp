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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<TreeNode *> cur;
        vector<TreeNode *> pre;
        vector<vector<int> > result;
        vector<int> vl;
        //if(root == NULL) return result;
        if(root){
            cur.push_back(root);
            vl.push_back(root->val);
        }
        int level = 0;
        while(!cur.empty()){
            level++;
            result.push_back(vl);
            swap(cur, pre);
            cur.clear();
            vl.clear();
            for(int i = 0; i < pre.size(); ++i) {
                if(pre[i]->left) {
                    cur.push_back(pre[i]->left);
                    vl.push_back(pre[i]->left->val);
                }
                if(pre[i]->right) {
                    cur.push_back(pre[i]->right);
                    vl.push_back(pre[i]->right->val);
                }
            }
            if(level & 1) {
//                reverse(cur.begin(), cur.end());
                reverse(vl.begin(), vl.end());
            }
        }
        return result;
    }
};
