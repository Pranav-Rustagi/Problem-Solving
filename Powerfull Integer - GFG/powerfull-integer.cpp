//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &in,int k){
        int sz = 0;
        for(auto i : in)    sz = max(sz, i[1]);
        vector<int> v(sz + 2, 0);
        for(auto i : in) {
            v[i[0]]++;
            v[i[1] + 1]--;
        }
        
        int ans = -1;
        for(int i = 1 ; i < sz + 2; i++) {
            v[i] += v[i - 1];
            if(v[i] >= k) {
                ans = i;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends