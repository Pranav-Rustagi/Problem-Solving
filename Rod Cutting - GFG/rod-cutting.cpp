//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(vector<int>& dp, int price[], int len) {
        if(dp[len] != -1) 
            return dp[len];
        
        for(int i = 0 ; i < len ; i++)
            dp[len] = max(dp[len], price[i] + solve(dp, price, len - i - 1));
            
        return dp[len];
    }
    
    int cutRod(int price[], int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        return solve(dp, price, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends