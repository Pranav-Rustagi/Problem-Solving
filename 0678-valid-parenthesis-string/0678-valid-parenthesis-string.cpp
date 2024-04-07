class Solution {
public:
    bool solve(string& s, int dp[][201], int ind, int n, int score = 100) {
        if(ind == n) {
            return score == 100;
        }
        
        if(score < 100) {
            return false;
        }
        
        if(dp[ind][score] != -1) {
            return dp[ind][score];
        }
        
        if(s[ind] == '(') {
            dp[ind][score] = solve(s, dp, ind + 1, n, score + 1);
        } else if(s[ind] == ')') {
            dp[ind][score] = solve(s, dp, ind + 1, n, score - 1);
        } else {
            dp[ind][score] = solve(s, dp, ind + 1, n, score) || solve(s, dp, ind + 1, n, score + 1) || solve(s, dp, ind + 1, n, score - 1);
        }
        
        return dp[ind][score];
    }
    
    bool checkValidString(string s) {
        int n = s.size();
        int dp[n][201];
        memset(dp, -1, sizeof(dp));
        return solve(s, dp, 0, n, 100);
    }
};