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
    bool hasPath(TreeNode *root, int sum) {
        if(root) {
            sum -= root -> val;
            if(root -> left || root -> right)
                return hasPath(root -> left, sum) || hasPath(root -> right, sum);
            else
                return sum == 0;
        } else {
            return false;
        }
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return root && hasPath(root, targetSum);
    }
};