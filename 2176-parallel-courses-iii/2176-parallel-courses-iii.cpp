class Solution {
public:
    int solve(int i, vector<int> graph[], vector<int>& time, int dp[]) {
        if(dp[i] != -1) {
            return dp[i];
        }

        dp[i] = time[i];
        for(int c : graph[i]) {
            dp[i] = max(dp[i], time[i] + solve(c, graph, time, dp));
        }
        return dp[i];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> graph[n];
        for(auto r : relations) {
            graph[r[1] - 1].push_back(r[0] - 1);
        }

        int dp[n], res = INT_MIN;
        memset(dp, -1, sizeof(dp));

        for(int i = 0 ; i < n ; i++) {
            res = max(res, solve(i, graph, time, dp));
        }

        return res;
    }
};