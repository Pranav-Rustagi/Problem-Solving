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
        queue<Node*> q1, q2;
        q1.push(root);
        while(!q1.empty()) {
            v.push_back({});
            while(!q1.empty()) {
                root = q1.front();
                q1.pop();
                v.back().push_back(root -> val);
                for(auto& node : root -> children) {
                    q2.push(node);
                }
            }
            q1 = q2;
            q2 = {};
        }
        return v;
    }
};