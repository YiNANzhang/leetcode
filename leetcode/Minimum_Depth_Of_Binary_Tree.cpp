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
    int minDepth(TreeNode *root) {
        int min_dep = INT_MAX;
        if(root == nullptr) return 0;
        minDepth(root, min_dep, 1);
        return min_dep;
    }
    void minDepth(TreeNode *root, int &min_dep, int level) {
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) {
             min_dep = min(min_dep, level); 
        }
        minDepth(root->left, min_dep, level+1);
        minDepth(root->right, min_dep, level+1);
    }
    
};
