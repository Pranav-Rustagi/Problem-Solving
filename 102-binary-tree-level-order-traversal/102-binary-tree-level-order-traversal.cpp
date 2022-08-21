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
    
    vector<vector<int>> levelOrder(TreeNode* root) {    
        if(root) {
            queue<TreeNode*> f, s;
            f.push(root);
            while(!f.empty()) {
                v.push_back({});
                while(!f.empty()) {
                    root = f.front();
                    f.pop();
                    if(root -> left)
                        s.push(root -> left);
                    if(root -> right)
                        s.push(root -> right);
                    v.back().push_back(root -> val);
                }
                
                f = s;
                s = {};
            }
        }
        return v;
    }
};