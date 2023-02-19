//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        int i = 0, j = 0, oCount = 0, res = INT_MIN;
        while(j < n) {
            if(arr[j++] == 'O')
                ++oCount;
            while(oCount > m) {
                if(arr[i++] == 'O') {
                    --oCount;
                }
            }
            res = max(res, j - i);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends