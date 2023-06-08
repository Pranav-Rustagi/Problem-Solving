//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int minCoins(int coins[], int M, int V) {
	    int dp[V + 1] = {0};
	    for(int i = 1 ; i <= V ; i++)
	        dp[i] = -1;
	        
	    for(int i = 1 ; i <= V ; i++) {
	        for(int j = 0 ; j < M ; j++) {
	            if(coins[j] <= i && dp[i - coins[j]] != -1) {
	                int val = 1 + dp[i - coins[j]];
	                dp[i] = dp[i] == -1 ? val : min(dp[i], val);
	            }
	        }
	    }
	    
	    return dp[V];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends