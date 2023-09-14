class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> g;
        for(auto& v : tickets) {
            g[v[0]].push_back(v[1]);
        }

        for(auto & p : g) {
            sort(p.second.rbegin(), p.second.rend());
        }

        vector<string> res;

        function<void(const string&)> dfs = [&](const string& cur) {
            while(!g[cur].empty()) {
                string next = g[cur].back();
                g[cur].pop_back();
                dfs(next);
            }
            res.push_back(cur);
        };

        dfs("JFK");

        reverse(res.begin(), res.end());
        return res;
    }
};