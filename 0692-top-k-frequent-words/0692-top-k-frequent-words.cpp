class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(string& w : words)
            ++m[w];
        vector<pair<string, int>> v;
        for(auto & p : m)
            v.push_back({p.first, p.second});
        sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if(a.second == b.second)
                return a < b;
            return a.second > b.second;
        });
        
        vector<string> res;
        int iter = 0;
        while(k--) {
            res.push_back(v[iter++].first);
        }
        
        return res;
    }
};