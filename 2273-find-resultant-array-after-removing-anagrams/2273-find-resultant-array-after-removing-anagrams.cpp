class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> v, res;
        for(auto & w : words) {
            string cur = w;
            sort(cur.begin(), cur.end());
            if(v.size() == 0 || v.back() != cur) {
                v.push_back(cur);
                res.push_back(w);
            }
        }
        
        return res;
    }
};