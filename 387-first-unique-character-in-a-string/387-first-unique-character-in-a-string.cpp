class Solution {
public:
    vector<vector<int>> arr;
    
    Solution() {
        arr.resize(26, vector<int>());
    }
    
    int firstUniqChar(string s) {    
        for(int i = 0 ; i < s.size() ; ++i) {
            if(arr[s[i] - 'a'].size() < 2)
                arr[s[i] - 'a'].push_back(i);
        }
        
        int res = INT_MAX;
        for(auto& v : arr) {
            if(v.size() == 1) {
                res = min(res, v[0]);
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};