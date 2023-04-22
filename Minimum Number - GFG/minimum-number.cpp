//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        long long res = arr[0];
        for(int i = 1 ; i < n ; i++) {
            if(arr[i] < res) {
                res -= arr[i];
            } else if(arr[i] > res) {
                arr[i] = arr[i] - ((arr[i] / res) * res);
                i--;
            }
        }
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.minimumNumber(n,arr)<<endl;
    }
}
// } Driver Code Ends