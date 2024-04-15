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
    bool isLeaf(TreeNode* root) {
        return !root -> left && !root -> right;
    }
    
    void solve(TreeNode* root, int& res, int prevSum = 0) {
        prevSum = prevSum * 10 + root -> val;
        if(isLeaf(root)) {
            res += prevSum;
        } else {
            if(root -> left) {
                solve(root -> left, res, prevSum);
            }
            
            if(root -> right) {
                solve(root -> right, res, prevSum);
            }
        }
    }
    
    int sumNumbers(TreeNode* root, int prevSum = 0) {
        int res = 0;
        solve(root, res);
        return res;
    }
};