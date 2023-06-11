//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m) {
	    int s = 1, e = m;
	    while(s <= e) {
	        int mid = (s + e) >> 1;
	        long long val = 1;
	        for(int i = 0 ; i < n ; i++) {
	            val *= mid;
	            if(val > m) {
	                break;
	            }
	        }
	        
	        if(val == m) {
	            return mid;
	        } else if(val < m) {
	            s = mid + 1;
	        } else {
	            e = mid - 1;
	        }
	    }
	    
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends