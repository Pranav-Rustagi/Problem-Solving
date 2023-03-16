//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        sort(arr, arr + n);
        int missing = n, repeated = n;
        for(int i = 0 ; i < n ; i++) {
            if((i == 0 && arr[i] == 2) || (i && arr[i] - arr[i - 1] > 1)) {
                missing = arr[i] - 1;
            }

            if(i && arr[i] == arr[i - 1]) {
                repeated = arr[i];
            }
        }
        int *res(new int[2]{ repeated, missing });
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