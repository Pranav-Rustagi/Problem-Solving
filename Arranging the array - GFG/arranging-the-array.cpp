//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n) {
            vector<int> tempP;
            for(int i = 0, in = 0 ; i < n ; i++) {
                if(arr[i] < 0) {
                    arr[in++] = arr[i];
                } else {
                    tempP.push_back(arr[i]);
                }
            }
            
            for(int it = tempP.size() - 1 ; it >= 0 ; it--) {
                arr[--n] = tempP[it];
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends