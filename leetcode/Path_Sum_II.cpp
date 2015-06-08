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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ret;
        if(root == nullptr) return ret;
        if(root->left == nullptr && root->right == nullptr) {
            if(root->val == sum) {
                vector<int> tmp({root->val});
                ret.push_back(tmp);
                return ret;
            } else {
                ret.clear();
                return ret;
            }
        }
        vector<vector<int> > left = pathSum(root->left, sum - root->val);
        vector<vector<int> > right = pathSum(root->right, sum - root->val);
        for(auto i:left) {
            i.insert(i.begin(), root->val);
            ret.push_back(i);
        }
        for(auto j:right) {
            j.insert(j.begin(), root->val);
            ret.push_back(j);
        }
        return ret;
    }
};
