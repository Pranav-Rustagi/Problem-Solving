//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(vector<int>& arr, vector<int>& v, int N, int ind = 0, int sum = 0) {
        if(ind == N) {
            v.push_back(sum);
        } else {
            solve(arr, v, N, ind + 1, sum);
            solve(arr, v, N, ind + 1, sum + arr[ind]);
        }
    }
    
    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> v;
        solve(arr, v, N);
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends