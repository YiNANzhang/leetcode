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
        vector<TreeNode*> pathParP;
        vector<TreeNode*> pathParQ;
        findPath(root, p, pathParP);
        findPath(root, q, pathParQ);
        TreeNode *result = NULL;
        for (int i = 0; i < pathParP.size() && i < pathParQ.size(); ++i) {
            if (pathParP[i] == pathParQ[i]) result = pathParP[i];
        }
        return result;
    }
    
    void findPath(TreeNode *root, TreeNode *p, vector<TreeNode*> &path) {
        if (root == NULL || p == NULL) return;
        path.push_back(root);
        //stack<TreeNode*> tmpstck;
        if (path.back()->val == p->val) return;
        //TreeNode *cur;
        while (!path.empty()) {
            TreeNode *cur = path.back();
            while (cur->left) {
                path.push_back(cur->left);
                if (cur->left == p) return;
                cur = cur->left;
            }
            TreeNode *pre = NULL;
            while (!path.empty()) {
                cur = path.back();
                if (pre == cur->right || cur->right == NULL) {
                    path.pop_back();
                    pre = cur;
                } else {
                    //if (cur->right)
                    path.push_back(cur->right);
                    if (cur->right == p) return;
                    cur = cur->right;
                    break;
                }
            }
        }
    }
};
