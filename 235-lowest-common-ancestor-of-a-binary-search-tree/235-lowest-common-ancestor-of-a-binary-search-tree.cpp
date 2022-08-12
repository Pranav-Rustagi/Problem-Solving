/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minV = min(p -> val, q -> val), maxV = max(p -> val, q -> val);
        
        while(root) {
            if(root == p || root == q || (root -> val > minV && root -> val < maxV))
                break;
            root = (q -> val < root -> val) ? root -> left : root -> right;
        }
        return root;
    }
};