/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> stck;
    void toStack(TreeNode *root){
        if(root){
            TreeNode *rNode = root;
            while(rNode){
                stck.push(rNode);
                rNode = rNode->left;
            }
        }        
    }
public:
    BSTIterator(TreeNode *root) {
        toStack(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stck.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *top = stck.top();
        stck.pop();
        toStack(top->right);
        return top->val;
    }
};


/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
