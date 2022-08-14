class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    
    void solve(vector<int>& c, int t, int i) {
        if(t == 0)
            res.push_back(temp);
        else if(t > 0) {
            for(int j = i ; j < c.size() ; ++j) {
                temp.push_back(c[j]);
                solve(c, t - c[j], j + 1);
                temp.pop_back();
                while(j + 1 < c.size() && c[j] == c[j + 1])
                    ++j;
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        solve(c, t, 0);
        return res;
    }
};