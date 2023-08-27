class Solution {
public:
    bool solve(vector<int>& stones, int dp[2001][2001], int n, int ind, int prev) {
        if(ind >= n - 1) {
            return true;
        }

        if(dp[ind][prev] != -1) {
            return dp[ind][prev];
        }
        
        dp[ind][prev] = 0;
        int indn = lower_bound(stones.begin() + ind + 1, stones.end(), stones[ind] + prev - 1) - stones.begin();
        while(indn < n && stones[indn] - stones[ind] <= prev + 1) {
            dp[ind][prev] = solve(stones, dp, n, indn, stones[indn] - stones[ind]);
            if(dp[ind][prev]) {
                return true;
            }
            indn++;
        }
        return dp[ind][prev];
    }
    bool canCross(vector<int>& stones) {
        int arr[2001][2001];
        memset(arr, -1, sizeof(arr));
        return solve(stones, arr, stones.size(), 0, 0);
    }
};