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
    //vector<TreeNode *> result;
	//int count;
public:
    vector<TreeNode *> generateTrees(int n) {
		vector<TreeNode *> result;
		if(n == 0) result.push_back(NULL);
		result = generateTrees(1, n);
        return result;
    }
    vector<TreeNode *> generateTrees(int begin, int end) {
        vector<TreeNode *> subTree;
        if(begin > end) {
            subTree.push_back(NULL);
        }
        for(int i = begin; i <= end; ++i) {
            vector<TreeNode *> left = generateTrees(begin, i-1);
            vector<TreeNode *> right = generateTrees(i+1, end);
            for(auto j : left) {
                for(auto k : right) {
                    TreeNode * cur = new TreeNode(i);
                    cur->left = j;
                    cur->right = k;
                    subTree.push_back(cur);
                }
            }
        }
        return subTree;
    }

};
