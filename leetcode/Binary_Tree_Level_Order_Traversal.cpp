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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        vector<TreeNode *> prev, cur;
        vector<int> tmp;
        if(root != nullptr) {
            prev.push_back(root);
        }
        while(!prev.empty()) {
            tmp.clear();
            for(auto i : prev) {
                tmp.push_back(i->val);
                if(i->left) cur.push_back(i->left);
                if(i->right) cur.push_back(i->right);
            }
            result.push_back(tmp);
            prev.clear();
            swap(prev, cur);
        }
        return result;
    }
};


//recursive

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        levelOrder(result, root, 0);
        return result;
    }
    
    void levelOrder(vector<vector<int> > &result, TreeNode *root, int level) {
        if(root == nullptr) return;
        if(level >= result.size()) {
            result.push_back(vector<int>() );
        }
        result[level].push_back(root->val);
        levelOrder(result, root->left, level+1);
        levelOrder(result, root->right, level+1);
    }
};
