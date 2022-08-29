class Solution {
public:
    vector<int> dp;
    
    Solution() {
        dp.resize(10001, -1);
    }
    
    int numSquares(int n) {
        if(n == 0)
            return 0;
        if(n < 0)
            return INT_MAX;
        if(dp[n] != -1)
            return dp[n];
        int res = INT_MAX;
        for(int i = sqrt(n) ; i > 0 ; --i) {
            res = min(res, 1 + numSquares(n - (i * i)));
        }
        return (dp[n] = res);
    }
};