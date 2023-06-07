//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int l = 0, r = 0, count = 0;
        while(r < n - 1) {
            count++;
            int mind = l;
            for(int i = l ; i <= r ; i++) {
                if(mind + arr[mind] < i + arr[i]) {
                    mind = i;
                }
            }
            
            if(mind + arr[mind] <= r) {
                return -1;
            }
            l = mind + 1;
            r = mind + arr[mind];
        }
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends