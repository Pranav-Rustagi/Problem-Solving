//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string& s) {
        int count = 0;
        bool allow = true;
        while(!s.empty()) {
            int n = s.size();
            count++;
            if(allow && (n & 1) == 0) {
                string temp = s.substr(0, n >> 1);
                if(temp == s.substr(n >> 1)) {
                    allow = false;
                    s = temp;
                } else {
                    s.pop_back();
                }
            } else {
                s.pop_back();
            }
        }
        return count;
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
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends