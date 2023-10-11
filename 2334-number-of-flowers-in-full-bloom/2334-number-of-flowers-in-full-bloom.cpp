class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int sm = INT_MAX, lg = INT_MIN;
        map<int, int> m;
        for(auto v : flowers) {
            m[v[0]]++;
            m[v[1] + 1]--;
            sm = min(sm, v[0]);
            lg = max(lg, v[1]);
        }

        int prev = 0;
        for(auto & p : m) {
            prev = p.second += prev;
        }

        vector<int> res;
        for(int p : people) {
            if(p < sm || p > lg) {
                res.push_back(0);
            } else {
                auto iter = --m.upper_bound(p);
                res.push_back(iter -> second);
            }
        }
        return res;
    }
};