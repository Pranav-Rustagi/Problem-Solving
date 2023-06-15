//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        string res;
        
        for(int i = 0 ; i < S.size() ; ) {
            int count = 1, j = i + 1;
            while(j < S.size() && S[j] == S[i]) {
                j++;
                count++;
            }
            
            int tempi = i - 1, tempj = j;
            while(tempi >= 0 && tempj < S.size() && S[tempi] == S[tempj]) {
                tempi--;
                tempj++;
                count += 2;
            }
            
            if(res.size() < (count)) {
                res = S.substr(tempi + 1, count);
            }
            i = j;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends