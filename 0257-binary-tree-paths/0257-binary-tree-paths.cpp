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
    vector<string> v;
    void traverse(TreeNode* root, string s = "") {
        if(root) {
            s += to_string(root -> val) + "->";
            if(root -> right || root -> left) {
                traverse(root -> left, s);
                traverse(root -> right, s);
            } else {
                s.pop_back();
                s.pop_back();
                v.push_back(s);
            }
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        traverse(root);
        return v;
    }
};