//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge) {
      int arr[N] = {0};
      for(int i = 0 ; i < N ; i++) {
          if(Edge[i] != -1) {
              arr[Edge[i]] += i;
          }
      }
      
      int resInd = 0;
      for(int i = N - 1, max = 0 ; i >= 0 ; i--) {
          if(arr[i] > max) {
              max = arr[i];
              resInd = i;
          }
      }
      
      return resInd;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends