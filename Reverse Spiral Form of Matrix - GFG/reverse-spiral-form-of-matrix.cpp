//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        vector<int> v;
        int r1 = 0, r2 = a.size() - 1, c1 = -1, c2 = a[0].size() - 1;
        while(r1 <= r2 && c1 <= c2) {
            if(r1 <= r2)
                for(int iter = ++c1 ; iter <= c2 ; ++iter)
                    v.push_back(a[r1][iter]);
            if(c1 <= c2)
                for(int iter = ++r1 ; iter <= r2 ; ++iter)
                    v.push_back(a[iter][c2]);
            if(r1 <= r2)
                for(int iter = --c2 ; iter >= c1 ; --iter)
                    v.push_back(a[r2][iter]);
            if(c1 <= c2)
                for(int iter = --r2 ; iter >= r1 ; --iter)
                    v.push_back(a[iter][c1]);
        }
        
        reverse(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends