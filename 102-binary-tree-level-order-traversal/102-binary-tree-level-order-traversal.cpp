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
    vector<vector<int>> v;
    
    void s(TreeNode* r, int l) {
        if(r) {
            if(l == v.size())
                v.push_back({});
            v[l].push_back(r -> val);
            s(r -> left, l + 1);
            s(r -> right, l + 1);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {    
        s(root, 0);
        return v;
    }
};