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
    map<int, map<int, multiset<int>>> m;
    vector<vector<int>> v;
    
    void solve(TreeNode* root, int col = 0, int row = 0) {
        if(root) {
            m[col][row].insert(root -> val);
            solve(root -> left, col - 1, row + 1);
            solve(root -> right, col + 1, row + 1);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root);
        for(auto & mr : m) {
            vector<int> temp;
            for(auto & s : mr.second) {
                for(auto & el : s.second) {
                    temp.push_back(el);
                }
            }
            v.push_back(temp);
        }
        return v;
    }
};