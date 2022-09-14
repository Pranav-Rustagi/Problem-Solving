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
    int res = 0;
    int arr[10];
    
    void traverse(TreeNode* root) {
        if(root) {
            ++arr[root -> val];
            
            if(!root -> left && !root -> right) {
                int oddC = 0;
                for(int i = 0 ; i < 10 ; ++i)
                    if(arr[i] & 1)
                        if(++oddC > 1)
                            break;
                if(oddC <= 1)
                    ++res;
            } else {
                traverse(root -> left);
                traverse(root -> right);
            }
            --arr[root -> val];
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        traverse(root);
        return res;
    }
};