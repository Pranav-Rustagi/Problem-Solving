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
    vector<int> largestValues(TreeNode* root) {
        vector<int> resV;
        if(!root)   return resV;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int res = q.front() -> val;
            int n = q.size();
            while(n--) {
                res = max(res, q.front() -> val);
                if(q.front() -> left) {
                    q.push(q.front() -> left);
                }
                if(q.front() -> right) {
                    q.push(q.front() -> right);
                }
                q.pop();
            }
            resV.push_back(res);
        }

        return resV;
    }
};