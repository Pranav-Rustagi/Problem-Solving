class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res;
        map<int, int> m;
        for(auto & el : changed)
            ++m[el];
        
        for(auto & p : m) {
            if(p.first) {
                if(m.find(p.first << 1) == m.end() || m[p.first << 1] < p.second)
                    return {};
                m[p.first << 1] -= p.second;
                if(m[p.first << 1] == 0)
                    m.erase(p.first << 1);
                while(p.second--)
                    res.push_back(p.first);
            } else {
                if(p.second & 1)
                    return {};
                while(p.second) {
                    res.push_back((p.second -= 2) && 0);
                }
            }
        }
        
        return res;
    }
};