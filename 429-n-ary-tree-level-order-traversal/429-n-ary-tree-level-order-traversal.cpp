/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> v;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            v.push_back({});
            int sz = q.size();
            while(sz--) {
                root = q.front();
                q.pop();
                v.back().push_back(root -> val);
                for(auto& node : root -> children) {
                    q.push(node);
                }
            }
        }
        return v;
    }
};