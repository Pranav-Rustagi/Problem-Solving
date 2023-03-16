//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        long long sum_all = 0, sumA = 0, sumSq_all = 0, sumSqA = 0, sz = n;
        for(long long i = 0 ; i < n ; i++) {
            sum_all += i + 1;
            sumA += arr[i];
            sumSq_all += (i + 1) * (i + 1);
            sumSqA += ((long long)(arr[i])) * arr[i];
        }

        long long diff = sum_all - sumA;
        long long diffSq = sumSq_all - sumSqA;

        long long sum = diffSq / diff;
        int missing = (sum + diff) >> 1;
        int repeated = sum - missing;
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