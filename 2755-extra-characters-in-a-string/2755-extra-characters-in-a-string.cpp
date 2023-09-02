class Solution {
public:
    int dp[51];

    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        memset(dp, -1, sizeof(dp));
    }

    int minExtraChar(string& s, vector<string>& words, int i = 0) {
        if(i == s.size())   return 0;
        if(dp[i] != -1)     return dp[i];

        dp[i] = s.size();
        for(auto w : words) {
            int len = w.size();
            if(s.substr(i, len) == w) {
                dp[i] = min(dp[i], minExtraChar(s, words, i + len));
            }
        }

        return dp[i] = min(dp[i], 1 + minExtraChar(s, words, i + 1));
    }
};