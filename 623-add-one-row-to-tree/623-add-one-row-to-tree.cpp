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
    void solve(TreeNode* root, int& val, int depth) {
        if(root) {
            if(depth == 2) {
                root -> left = new TreeNode(val, root -> left, NULL);
                root -> right = new TreeNode(val, NULL, root -> right);
            } else {
                solve(root -> left, val, depth - 1);
                solve(root -> right, val, depth - 1);
            }
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int& val, int depth) {
        if(depth == 1)
            return new TreeNode(val, root, NULL);
        solve(root, val, depth);
        return root;
    }
};