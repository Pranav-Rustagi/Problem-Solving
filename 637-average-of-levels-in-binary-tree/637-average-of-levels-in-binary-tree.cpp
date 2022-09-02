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
    vector<double> v;
    
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        q1.push(root);
        while(!q1.empty()) {
            int n = 0;
            v.push_back(0);
            while(!q1.empty()) {
                root = q1.front();
                q1.pop();
                if(root -> left)
                    q2.push(root -> left);
                if(root -> right)
                    q2.push(root -> right);
                v.back() += root -> val;
                ++n;
            }
            
            v.back() /= n;
            q1 = q2;
            q2 = queue<TreeNode*>();
        }
        
        return v;
    }
};