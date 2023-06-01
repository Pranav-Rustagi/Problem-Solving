//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int x = 0;
        for(int i = 0 ; i < n ; i++) {
            x ^= (arr[i] ^ (i + 1));
        }
        
        int b = 1;
        while(!(x & b)) {
            b <<= 1;
        }
        
        int x1 = 0, x2 = 0;
        for(int i = 0 ; i < n ; i++) {
            if((i + 1) & b) {
                x1 ^= (i + 1);
            } else {
                x2 ^= (i + 1);
            }
            
            if(arr[i] & b) {
                x1 ^= arr[i];
            } else {
                x2 ^= arr[i];
            }
        }
        
        for(int i = 0 ; i < n ; i++) {
            if(x2 == arr[i]) {
                swap(x1, x2);
                break;
            }
        }
        return { x1, x2 };
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
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