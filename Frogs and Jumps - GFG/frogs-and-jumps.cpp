//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        sort(frogs, frogs + N);
        vector<bool> v(leaves + 1, false);
        for(int i = 0 ; i < N ; i++) {
            if(v[frogs[i]] == false) {
                int j = frogs[i];
                while(j <= leaves) {
                    v[j] = true;
                    j += frogs[i];
                }
            }
        }
        
        int ct = 0;
        while(leaves) {
            if(!v[leaves--]) {
                ct++;
            }
        }
        return ct;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends