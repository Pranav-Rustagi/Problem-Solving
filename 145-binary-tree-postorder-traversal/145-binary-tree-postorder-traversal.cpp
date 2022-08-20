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
    vector<int> v;
    
    void t(TreeNode* r) {
        if(r) {
            t(r -> left);
            t(r -> right);
            v.push_back(r -> val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        t(root);
        return v;
    }
};