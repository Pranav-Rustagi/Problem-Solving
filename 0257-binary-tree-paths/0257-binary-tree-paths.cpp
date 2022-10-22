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
    vector<int> els;
    void traverse(TreeNode* root) {
        if(root) {
            els.push_back(root -> val);
            if(root -> left || root -> right) {
                traverse(root -> left);
                traverse(root -> right);
            } else {
                string s;
                for(int & el : els)
                    s += to_string(el) + "->";
                s.pop_back();
                s.pop_back();
                v.push_back(s);
            }
            els.pop_back();
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        traverse(root);
        return v;
    }
};