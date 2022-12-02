//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        int i = 0, j = 0;
        while(i < M && j < N) {
            while(i < M && S[i] == '#')
                ++i;
            while(j < N && T[j] == '#')
                ++j;
            if(i == M || j == N)
                break;
            if((S[i] != T[j]) || (S[i] == 'A' && i < j) || (S[i] == 'B' && i > j))
                return false;
            ++i;
            ++j;
        }
        
        while(i < M && S[i] == '#')
            ++i;
        while(j < N && T[j] == '#')
            ++j;
        
        return (i == M && j == N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends