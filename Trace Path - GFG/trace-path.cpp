//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int xmin = 0, xmax = 0, ymin = 0, ymax = 0, x = 0, y = 0;
        for(char ch : s) {
            if(ch == 'U') {
                y--;
                ymin = min(y, ymin);
            } else if(ch == 'D') {
                y++;
                ymax = max(ymax, y);
            } else if(ch == 'L') {
                x--;
                xmin = min(x, xmin);
            } else {
                x++;
                xmax = max(xmax, x);
            }
        }
        
        return (xmax - xmin + 1 <= m) && (ymax - ymin + 1 <= n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends