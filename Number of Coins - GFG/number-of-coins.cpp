//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<int> v(V + 1, -1);
	    v[0] = 0;
	    int sCoin = INT_MAX;
	    for(int i = 1 ; i <= V ; i++) {
	        for(int j = 0 ; j < M ; j++) {
	            if(i >= coins[j] && v[i - coins[j]] != -1 && (v[i] == -1 || v[i] > 1 + v[i - coins[j]])) {
	                v[i] = 1 + v[i - coins[j]];
	            }
	        }
	    }
	    
	    return v[V];
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