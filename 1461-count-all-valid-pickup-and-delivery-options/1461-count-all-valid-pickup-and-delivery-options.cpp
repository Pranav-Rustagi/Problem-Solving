class Solution {
public:
    int countOrders(int n) {
        int dp[n];
        long long mod = 1e9 + 7;
        dp[0] = 1;
        for(int i = 1 ; i < n ; i++) {
            long long term = (i << 1) + 1;
            long long sum = (term * (term + 1)) >> 1;
            dp[i] = sum % mod * dp[i - 1] % mod;
        }
        return dp[n - 1];
    }
};