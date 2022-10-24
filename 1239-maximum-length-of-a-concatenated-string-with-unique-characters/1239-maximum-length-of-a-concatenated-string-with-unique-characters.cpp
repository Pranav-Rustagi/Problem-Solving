class Solution {
public:
    int res = 0;
    vector<int> v;
    Solution() {
        v.resize(26, 0);
    }
    
    void solve(vector<string>& arr, int ind, int cur) {
        if(ind == arr.size()) {
            res = max(res, cur);
        } else {
            solve(arr, ind + 1, cur);
            
            bool common = false;
            for(auto & ch : arr[ind])
                ++v[ch - 'a'];
            
            for(auto & ch : arr[ind]) {
                if(v[ch - 'a'] > 1) {
                    common = true;
                    break;
                }
            }
            
            if(common == false) {
                solve(arr, ind + 1, cur + arr[ind].size());
            }
            
            for(auto & ch : arr[ind])
                --v[ch - 'a'];
        }
    }
    
    int maxLength(vector<string>& arr) {
        sort(arr.begin(), arr.end(), [](const string & a, const string & b) {
            return a.size() > b.size();
        });
        
        solve(arr, 0, 0);
        return res;
    }
};