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
    unordered_map<int, int> m;
    int maxFreq = 0;
    
    void traverse(TreeNode* root) {
        if(root) {
            maxFreq = max(maxFreq, ++m[root -> val]);
            traverse(root -> left);
            traverse(root -> right);
        }
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        traverse(root);
        for(auto & p : m)
            if(p.second == maxFreq)
                v.push_back(p.first);
        return v;
    }
};