//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int N, int K, int prev, vector<vector<vector<int>>>& dp) {
        if(N < K)
            return 0;
        if(K == 0)
            return N == 0;
        if(dp[N][K][prev] == -1) {
            dp[N][K][prev] = 0;
            for(int i = prev ; i <= N ; i++)
                dp[N][K][prev] += solve(N - i, K - 1, i, dp);
        }
        return dp[N][K][prev];
    }
    int countWaystoDivide(int N, int K) {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(K + 1, vector<int>(N + 1, -1)));
        return solve(N, K, 1, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends