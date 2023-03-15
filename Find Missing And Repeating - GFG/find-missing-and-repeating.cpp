//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        vector<int> count(n, 0);
        for(int i = 0 ; i < n ; i++) {
            count[arr[i] - 1]++;
        }

        int missing, repeated;
        for(int i = 0 ; i < n ; i++) {
            if(count[i] == 0) {
                missing = i + 1;
            } else if(count[i] == 2) {
                repeated = i + 1;
            }
        }
        int *res(new int[2]{repeated, missing});
        return res;
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