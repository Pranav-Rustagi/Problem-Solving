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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            return new TreeNode(val, root, NULL);
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(depth > 2) {
            int n = q.size();
            while(n--) {
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp -> left) {
                    q.push(temp -> left);
                }
                
                if(temp -> right) {
                    q.push(temp -> right);
                }
            }
            depth--;
        }
        
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            temp -> left = new TreeNode(val, temp -> left, NULL);
            temp -> right = new TreeNode(val, NULL, temp -> right);
        }
        
        return root;
    }
};