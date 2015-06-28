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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            if(preorder.size()==0 || inorder.size()==0) return nullptr;
            TreeNode *root;  
			buildTree(root, preorder.begin(), inorder.begin(), inorder.end());
			return root;
	}
	
	template<typename iter>
		void buildTree(TreeNode * &root, iter pre_begin, iter in_begin, iter in_end){
		if(in_begin == in_end) return;
		root = new TreeNode(*pre_begin);
		iter start=in_begin;
		iter end = in_end;
		for(;start!=end;++start){
			if(*pre_begin == *start)
				break;
		}
		auto left_size = distance(in_begin, start);
		buildTree(root->left, next(pre_begin), in_begin, start);
		buildTree(root->right, next(pre_begin, left_size+1), next(start), in_end);
		}
    
    
};
