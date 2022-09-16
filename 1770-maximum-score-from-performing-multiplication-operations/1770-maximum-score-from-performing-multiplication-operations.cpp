class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int>& n, vector<int>& m, int iter, int s, int e) {
        if(iter == m.size())
            return 0;
        if(dp[iter][s] != INT_MIN)
            return dp[iter][s];
        int res1 = n[s] * m[iter] + solve(n, m, iter + 1, s + 1, e);
        int res2 = n[e] * m[iter] + solve(n, m, iter + 1, s, e - 1);
        return (dp[iter][s] = max(res1, res2));
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        dp.resize(multipliers.size() + 1, vector<int>(multipliers.size() + 1, INT_MIN));
        return solve(nums, multipliers, 0, 0, nums.size() - 1);
    }
};