//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string& S, string& T) {
        int iterS = 0, iterT = 0;
        while(iterS < S.size() && iterT < T.size()) {
            string num;
            while(T[iterT] >= '0' && T[iterT] <= '9') {
                num.push_back(T[iterT++]);
            }
            
            if(num.size()) {
                int ct = stoi(num);
                while(ct--) {
                    iterS++;
                }
            }
            
            if(iterT == T.size() || iterS == S.size())
                break;
            
            if(S[iterS] != T[iterT])
                return false;
            iterT++;
            iterS++;
        }
        return (iterT == T.size() && iterS == S.size());
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends