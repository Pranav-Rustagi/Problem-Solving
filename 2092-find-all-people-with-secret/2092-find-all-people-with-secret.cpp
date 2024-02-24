class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int, int>> adj[n];
        vector<int> res = { 0 };
        queue<int> q;
        
        int knowsAt[n];
        memset(knowsAt, -1, sizeof(knowsAt));
        
        adj[0].push_back({ firstPerson, 0 });
        for(auto m : meetings) {
            adj[m[0]].push_back({ m[1], m[2] });
            adj[m[1]].push_back({ m[0], m[2] });
        }
        
        knowsAt[0] = 0;
        q.push(0);
        
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            
            for(auto p : adj[t]) {
                if(p.second >= knowsAt[t]) {
                    if(knowsAt[p.first] == -1) {
                        res.push_back(p.first);
                    }
                    
                    if(knowsAt[p.first] == -1 || knowsAt[p.first] > p.second) {
                        knowsAt[p.first] = p.second;
                        q.push(p.first);
                    }
                }
            }
        }
        
        return res;
    }
};