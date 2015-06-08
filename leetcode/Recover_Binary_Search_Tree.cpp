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
    void recoverTree(TreeNode *root) {
        TreeNode *first, *next, *second;
        first = nullptr;
        next = nullptr;
        second = nullptr;
        //stack<TreeNode *> s;
        TreeNode *prev, *cur = root;
        prev = nullptr;
        while(cur) {
            if(cur->left == nullptr) {
                if(prev != nullptr && prev->val > cur->val) {
                    if(first == nullptr) {
                        first = prev;
                        next = cur;
                    } else {
                        second = cur;
                        break;
                    }
                }
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode *node = cur->left;
                while(node->right != nullptr && node->right != cur) 
                    node = node->right;
                if(node->right == nullptr) {
                    node->right = cur;
                    cur = cur->left;
                } else {
                    if(prev != nullptr && prev->val > cur->val) {
                        if(first == nullptr) {
                            first = prev;
                            next = cur;
                        } else {
                            second = cur;
                       //     break;
                        }
                    }
                    prev = cur;
                    cur = cur->right;
                    node->right = nullptr;
                }
            }
        }
        if(second != nullptr) swap(first->val, second->val);
        else swap(first->val, next->val);
    }
};
