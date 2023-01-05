//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<vector<int>> v;
        vector<int> res;
        
        for(int i = 0 ; i < N ; i++) {
            v.push_back({ S[i], F[i], i + 1 });
        }
        
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] == b[1]) ? (a[2] < b[2]) : (a[1] < b[1]);
        });
        
        
        for(int i = 0, prevEnd = -1 ; i < N ; i++) {
            if(prevEnd < v[i][0]) {
                prevEnd = v[i][1];
                res.push_back(v[i][2]);
            }
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends