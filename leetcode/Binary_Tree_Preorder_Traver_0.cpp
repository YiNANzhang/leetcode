class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while(cur != nullptr || !s.empty()) {
            if(cur) {
                result.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top()->right;
                s.pop();
            }
        }
        return result;
    }
};
