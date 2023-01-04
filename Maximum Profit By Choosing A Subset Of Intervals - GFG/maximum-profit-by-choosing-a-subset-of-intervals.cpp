//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> dp;
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        dp.resize(intervals.size(), -1);
        sort(intervals.begin(), intervals.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[1] < b[1];
        });
        dp[0] = intervals[0][2];
        for(int i = 1 ; i < intervals.size() ; i++) {
            int s = 0, e = i - 1;
            int ind = -1;
            while(s <= e) {
                int mid = (s + e) / 2;
                if(intervals[mid][1] > intervals[i][0]) {
                    e--;
                } else {
                    ind = max(ind, s++);
                }
            }
            
            dp[i] = max(dp[i - 1], intervals[i][2] + (ind > -1 ? dp[ind] : 0));
        }
        
        return dp.back();
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends