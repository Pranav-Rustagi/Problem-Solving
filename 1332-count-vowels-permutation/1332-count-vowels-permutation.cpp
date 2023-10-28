class Solution {
public:
    const int mod = 1e9 + 7;

    int solve(int dp[][5], int n, int start) {
        if(n <= 1)  return n;
        if(dp[n][start] != -1) return dp[n][start];

        if(start == 0) {
            return dp[n][0] = solve(dp, n - 1, 1);
        } else if(start == 1) {
            return dp[n][1] = (solve(dp, n - 1, 0) + 0LL + solve(dp, n - 1, 2)) % mod;
        } else if(start == 2) {
            return dp[n][2] = (solve(dp, n - 1, 0) + 0LL + solve(dp, n - 1, 1) + solve(dp, n - 1, 3) + solve(dp, n - 1, 4)) % mod;
        } else if(start == 3) {
            return dp[n][3] = (solve(dp, n - 1, 2) + 0LL + solve(dp, n - 1, 4)) % mod;
        } else {
            return dp[n][4] = solve(dp, n - 1, 0);
        }
    }
    int countVowelPermutation(int n) {
        int dp[n + 1][5];
        memset(dp, -1, sizeof(dp));
        int res = 0;

        for(int i = 0 ; i < 5 ; i++) {
            res = (res + 0LL + solve(dp, n, i)) % mod;
        }
        return res;
    }
};