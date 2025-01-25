class Solution {
public:
    bool checkSafe(int node, vector<vector<int>>& g, bool status[], bool vis[], int n) {
        if(vis[node] == false) {
            vis[node] = true;

            bool res = true;
            for(int gnode : g[node]) {
                if(checkSafe(gnode, g, status, vis, n) == false) {
                    res = false;
                    break;
                }
            }
            status[node] = res;
        }
        
        return status[node];
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        
        int n = graph.size();
        bool status[n], vis[n];

        memset(status, false, sizeof(status));
        memset(vis, false, sizeof(vis));

        for(int i = 0 ; i < n ; i++) {
            if(checkSafe(i, graph, status, vis, n)) {
                res.push_back(i);
            }
        }

        return res;
    }
};