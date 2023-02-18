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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode*> q;
        TreeNode* newRoot = root;
        q.push(root);
        while(!q.empty()) {
            root = q.front();
            q.pop();
            swap(root -> left, root -> right);
            if(root -> left)
                q.push(root -> left);
            if(root -> right)
                q.push(root -> right);
        }
        return newRoot;
    }
};