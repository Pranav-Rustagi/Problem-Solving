//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        int mod[K] = {0};
        for(int i = 0 ; i < N ; ++i)
            ++mod[arr[i] % K];
            
        int res = (mod[0] > 0);
        if (!(K & 1) && mod[K >> 1])
            ++res;
            
        for(int i = 1, lim = (K - (!(K & 1))) >> 1 ; i <= lim ; ++i) {
            res += max(mod[i], mod[K - i]);
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends