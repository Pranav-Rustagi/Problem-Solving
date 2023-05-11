//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string& str) {
        int s = 0, e = str.size() - 1;
        int diff = 0;
        while(s <= e) {
            if(str[s] == '?' && str[e] == '?') {
                if(s && str[s - 1] != '?') {
                    str[s] = str[e] = str[s - 1];
                }
                s++;
                e--;
                continue;
            }
            else if(str[s] == '?') {
                str[s] = str[e];
            } else if(str[e] == '?') {
                str[e] = str[s];
            } else {
                if(str[s] != str[e]) {
                    return -1;
                }
            }
            if(s && str[s - 1] != '?') {
                diff += abs(str[s] - str[s - 1]);
            }
            if(e < str.size() - 1 && str[e + 1] != '?') {
                diff += abs(str[e] - str[e + 1]);
            }
            s++;
            e--;
        }
        return diff;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends