/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasOne(TreeNode* root) {
        if(!root)
            return false;
        if(root -> val == 1)
            return true;
        return hasOne(root -> right) || hasOne(root -> left);
    }
    
    void prune(TreeNode* root) {
        if(root) {
            if(hasOne(root -> left))
                prune(root -> left);
            else
                root -> left = NULL;
            
            if(hasOne(root -> right))
                prune(root -> right);
            else
                root -> right = NULL;
        }
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        prune(root);  
        return (root -> val == 0 && root -> left == NULL && root -> right == NULL) ? NULL : root;
    }
};