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
    vector<int> arr;
    
    void fillArr(TreeNode* root) {
        if(root) {
            fillArr(root -> left);
            arr.push_back(root -> val);
            fillArr(root -> right);
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        fillArr(root);
        for(int s = 0, e = arr.size() - 1 ; s < e ; ) {
            int sum = arr[s] + arr[e];
            if(sum == k)
                return true;
            else if(k > sum)
                ++s;
            else
                --e;
        }
        
        return false;
    }
};