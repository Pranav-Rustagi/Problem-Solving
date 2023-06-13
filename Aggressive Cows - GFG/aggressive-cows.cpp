//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int s = INT_MAX, e = stalls.back() - stalls[0];
        for(int i = 1 ; i < n ; i++) {
            s = min(s, stalls[i] - stalls[i - 1]);
        }
        
        int res;
        while(s <= e) {
            int m = (s + e) >> 1;
            int prev = -1, count = 0;
            for(int stall : stalls) {
                if(prev <= stall) {
                    prev = stall + m;
                    count++;
                }
            }
            
            if(count < k) {
                e = m - 1;
            } else {
                res = m;
                s = m + 1;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends