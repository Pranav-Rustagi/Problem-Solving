class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<long long>> dp(m, vector<long long>(n, -1)), freq(m, vector<long long>(n, 0));
        dp[startRow][startColumn] = 0;
        freq[startRow][startColumn] = 1;
        
        long long res = 0, mod = 1000000007;
        
        for(int move = 0 ; move < maxMove ; ++move) {
            for(int i = 0 ; i < m ; ++i) {
                for(int j = 0 ; j < n ; ++j) {
                    if(move != dp[i][j])
                        continue;
                    int temp = 0, setVal = dp[i][j] + 1;
                    
                    if(i - 1 < 0) {
                        ++temp;
                    }
                    else {
                        if(dp[i - 1][j] != setVal) {
                            dp[i - 1][j] = setVal;
                            freq[i - 1][j] = freq[i][j];
                        }
                        else
                            freq[i - 1][j] += freq[i][j];
                        freq[i - 1][j] %= mod;
                    }
                    
                    
                    if(i + 1 == m) {
                        ++temp;
                    }
                    else {
                        if(dp[i + 1][j] != setVal) {
                            dp[i + 1][j] = setVal;
                            freq[i + 1][j] = freq[i][j];
                        }
                        else
                            freq[i + 1][j] += freq[i][j];
                        freq[i + 1][j] %= mod;
                    }
                    
                    
                    if(j - 1 < 0) {
                        ++temp;
                    }
                    else {
                        if(dp[i][j - 1] != setVal) {
                            dp[i][j - 1] = setVal;
                            freq[i][j - 1] = freq[i][j];
                        }
                        else
                            freq[i][j - 1] += freq[i][j];
                        freq[i][j - 1] %= mod;
                    }
                    
                    
                    if(j + 1 == n) {
                        ++temp;
                    }
                    else {
                        if(dp[i][j + 1] != setVal) {
                            dp[i][j + 1] = setVal;
                            freq[i][j + 1] = freq[i][j];
                        }
                        else
                            freq[i][j + 1] += freq[i][j];
                        freq[i][j + 1] %= mod;
                    }
                    
                    res = (res + (temp * freq[i][j])) % mod;
                    freq[i][j] = 0;
                }
            }
        }
        
        return res;
    }
};