//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    if(n == 1)
	        return arr[0];
	        
	    arr[1] = max(arr[0], arr[1]);
	    for(int i = 2 ; i < n ; i++) {
	        arr[i] = max(arr[i] + arr[i - 2], arr[i - 1]);
	        
	    }
	    return max(arr[n - 1], arr[n - 2]);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends