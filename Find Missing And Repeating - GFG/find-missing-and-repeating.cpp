//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int xorV = 0;
        for(int i = 0 ; i < n ; i++) {
            xorV ^= ((i + 1) ^ arr[i]);
        }
        
        int pos = 1;
        while((pos & xorV) == 0)
            pos <<= 1;
            
        int val1 = 0, val2 = 0;
        for(int i = 0 ; i < n ; i++) {
            if(pos & arr[i]) {
                val1 ^= arr[i];
            } else {
                val2 ^= arr[i];
            }
            
            if((i + 1) & pos) {
                val1 ^= (i + 1);
            } else {
                val2 ^= (i + 1);
            }
        }
        
        int *r = new int[2];
        for(int i = 0 ; i < n ; i++) {
            if(arr[i] == val1) {
                r[0] = val1;
                r[1] = val2;
                break;
            } else if(arr[i] == val2) {
                r[0] = val2;
                r[1] = val1;
                break;
            }
        }
        return r;
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends