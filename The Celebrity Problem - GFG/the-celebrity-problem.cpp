//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        stack<int> s;
        for(int i = 0 ; i < n ; i++)
            s.push(i);
        while(s.size() > 1) {
            int fir = s.top();
            s.pop();
            int sec = s.top();
            s.pop();
            
            if(M[fir][sec]) {
                s.push(sec);
            } else {
                s.push(fir);
            }
        }
        
        int pknow = 0;
        for(int i = 0 ; i < n ; i++) {
            if(M[i][s.top()]) {
                pknow++;
            }
            
            if(M[s.top()][i]) {
                return -1;
            }
        }
        
        return pknow != n - 1 ? -1 : s.top();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends