class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> v;
        
        for(auto & s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        
        for(auto & vec : m) {
            v.push_back(vec.second);
        }
        
        return v;
    }
};