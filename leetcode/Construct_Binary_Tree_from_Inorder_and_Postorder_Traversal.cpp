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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder.rbegin(), inorder.rend(), postorder.rbegin(), postorder.rend());
    }
    
    template<typename iter>
    TreeNode * buildTree(iter in_begin, iter in_end, iter  pos_begin, iter pos_end) {
        if(in_begin == in_end || pos_begin == pos_end) return nullptr;
        TreeNode *root = new TreeNode(*pos_begin);
        auto find_in = find( in_begin, in_end, *pos_begin);
        auto leftSize = distance(in_begin, find_in);
        
        //auto find_pos = find( pos_begin, pos_end, *prev(find_in));
        
        root->right = buildTree(in_begin, find_in, next(pos_begin), next(pos_begin, leftSize+1));
        root->left = buildTree(next(find_in), in_end, next(pos_begin, leftSize+1), pos_end);
        return root;
    }
};
