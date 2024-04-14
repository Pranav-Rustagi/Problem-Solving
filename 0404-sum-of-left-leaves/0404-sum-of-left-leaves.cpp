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
        return !(root -> left || root -> right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            root = q.front();
            q.pop();
            
            if(root -> left) {
                if(isLeaf(root -> left)) {
                    res += root -> left -> val;
                } else {
                    q.push(root -> left);
                }
            } 
            
            if(root -> right) {
                q.push(root -> right);
            }
        }
        
        return res;
    }
};