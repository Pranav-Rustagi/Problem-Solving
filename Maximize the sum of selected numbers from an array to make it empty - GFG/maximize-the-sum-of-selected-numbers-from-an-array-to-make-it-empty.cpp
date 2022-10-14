//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        vector<int> v(100001, 0);
        int lim = INT_MIN, res = 0;
        while(n--) {
            ++v[a[n]];
            lim = max(lim, a[n]);
        }
        
        for(int i = lim ; i >= 0 ; --i) {
            res += (v[i] * i);
            if(i - 1 >= 0)
                v[i - 1] = max(0, v[i - 1] - v[i]);
        }
        
        return res;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends