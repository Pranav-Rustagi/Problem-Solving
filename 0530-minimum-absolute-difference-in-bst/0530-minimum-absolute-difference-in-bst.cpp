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
    int res = INT_MAX;
    void traverse(TreeNode* root) {
        if(root) {
            traverse(root -> left);
            if(v.size())
                res = min(res, abs(root -> val - v.back()));
            v.push_back(root -> val);
            traverse(root -> right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        traverse(root);
        return res;
    }
};