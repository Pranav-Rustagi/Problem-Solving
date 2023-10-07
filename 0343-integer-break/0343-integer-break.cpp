class Solution {
public:
    int integerBreak(int n) {
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        dp[1] = 1;
        for(int i = 2 ; i <= n ; i++) {
            for(int j = 1, lim = i >> 1 ; j <= lim ; j++) {
                dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
            }
        }
        return dp[n];
    }
};