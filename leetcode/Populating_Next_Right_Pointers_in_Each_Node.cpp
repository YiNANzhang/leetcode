/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        int level = 0;
        queue<pair<TreeLinkNode*, int> > q;
        if(root) {
            root->next = NULL;
            q.push(make_pair(root, level));
        }
        while(!q.empty()){
            pair<TreeLinkNode*, int> front = q.front();
            TreeLinkNode *cur = front.first;
            pair<TreeLinkNode*, int> prev = q.back();
            if(cur->right) {
                level = front.second+1;
                if(prev.second == level) {
                    cur->right->next = prev.first;
                }
                q.push(make_pair(cur->right, level));
            }
            if(cur->left) {
                prev = q.back();
                level = front.second+1;
                if(prev.second == level) {
                    cur->left->next  = prev.first;
                }
                q.push(make_pair(cur->left, level));
            }
            q.pop();
        }
    }
};
