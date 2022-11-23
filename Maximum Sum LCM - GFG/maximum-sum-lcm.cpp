//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long int maxSumLCM(int n) 
    {
        int sq = sqrt(n);
        long long sum = 0;
        for(int i = 1 ; i <= sq ; ++i) {
            if(n % i == 0) {
                sum += i + (n / i);
            }
        }
        
        if(n == sq * sq)
            sum -= sq;
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.maxSumLCM(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends