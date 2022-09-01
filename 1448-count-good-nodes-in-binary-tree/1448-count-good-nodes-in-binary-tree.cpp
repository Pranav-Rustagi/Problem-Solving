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
    int r = 0;
    
    void solve(TreeNode* root, int maxEl = INT_MIN) {
        if(root) {
            if(root -> val >= maxEl) {
                ++r;
            }
            
            maxEl = max(maxEl, root -> val);
            solve(root -> left, maxEl);
            solve(root -> right, maxEl);
        }
    }
    
    int goodNodes(TreeNode* root) {
        solve(root);
        return r;
    }
};