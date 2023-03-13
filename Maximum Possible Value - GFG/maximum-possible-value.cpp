//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
    //     long long res = 0;
        
    //     vector<int> left;
    //     for(int i = 0 ; i < N ; i++) {
    //         long count = B[i] >> 2;
    //         res += count * A[i] * 4;
    //         B[i] %= 4;
            
    //         if(B[i] > 1)
    //             left.push_back(A[i]);
    //     }
        
    //     sort(left.rbegin(), left.rend());
    //     for(int i = 1 ; i < left.size() ; i += 2) {
    //         res += (left[i] + left[i - 1]) << 1;
    //     }
        
    //     return res;
    long long mi=1e10;
          
          long long ans=0,totalSticks=0;
          for(int i=0;i<N;i++)
          {
                if(B[i]%2==1)
                B[i]--;
                
                if(B[i]>=2)
                {
                     mi=min(mi,(long long)A[i]);
                }
                totalSticks+= B[i];
                ans+= A[i]*B[i];
          }
          if(totalSticks%4!=0)
          {
                ans-=2*mi;
          }
          return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends