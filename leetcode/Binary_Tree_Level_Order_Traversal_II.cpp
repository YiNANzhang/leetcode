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
    vector<vector<int> > result;
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		transverse(root,1,result);
		std::reverse(result.begin(),result.end());
		return result;
	}

	void transverse(TreeNode *root, int i, vector<vector<int> >& result){
		if(!root)
			return;
		if(i>result.size())
		    result.push_back(vector<int>());
		result[i-1].push_back(root->val);
		//if(root->left)
		transverse(root->left,i+1,result);
		//if(root->right)
		transverse(root->right,i+1,result);
	}

};
