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
    bool shouldPrune(TreeNode* root) {
        if(!root) return false;
        bool hasOneOnLeft = shouldPrune(root -> left);
        bool hasOneOnRight = shouldPrune(root -> right);
        if(!hasOneOnLeft) root -> left = NULL;
        if(!hasOneOnRight) root -> right = NULL;
        return root -> val == 1 || hasOneOnLeft || hasOneOnRight;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(!shouldPrune(root))
            return NULL;
        return root;
    }
};