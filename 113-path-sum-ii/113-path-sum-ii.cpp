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
    vector<vector<int>> r;
    vector<int> v;
    void traverse(TreeNode* root, int sum) {
        if(root) {
            v.push_back(root -> val);
            sum -= root -> val;
            if (root -> left || root -> right) {
                traverse(root -> left, sum);
                traverse(root -> right, sum);
            } else if (sum == 0) {
                r.push_back(v);
            }
            v.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        traverse(root, targetSum);
        return r;
    }
};