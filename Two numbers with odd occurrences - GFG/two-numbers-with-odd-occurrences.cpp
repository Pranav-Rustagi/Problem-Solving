//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long x = 0;
        for(int i = 0 ; i < N ; ++i)
            x ^= Arr[i];
        int i = 1;
        while((x & i) == 0)
            i <<= 1;
        vector<long long int> r = {0,0};
        while(N--) {
            if(Arr[N] & i)
                r[0] ^= Arr[N];
            else
                r[1] ^= Arr[N];
        }
        
        if(r[0] < r[1])
            swap(r[0], r[1]);
        return r;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends