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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return buildBST(num, 0, num.size() );
    }
    
    TreeNode * buildBST(vector<int> &num, int begin, int end) {
        if(begin == end) return nullptr;
        int mid = begin + ((end - begin) >> 1);
        TreeNode * root = new TreeNode(num[mid]);
        root->left = buildBST(num, begin, mid);
        root->right = buildBST(num, mid+1, end);
        return root;
    }
};
