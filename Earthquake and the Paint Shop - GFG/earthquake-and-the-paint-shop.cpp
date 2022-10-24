//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct alphanumeric {
    string name;
    int count;
    alphanumeric(string s, int c) {
        name = s;
        count = c;
    }
};
class Solution {
  public:
    vector<alphanumeric> sortedStrings(int N, vector<string> A) {
        unordered_map<string, int> m;
        for(auto & s : A)
            ++m[s];
        vector<alphanumeric> v;
        for(auto & p : m) {
            v.push_back(*(new alphanumeric(p.first, p.second)));
        }
        
        sort(v.begin(), v.end(), [](const alphanumeric & a, const alphanumeric & b) {
            return a.name < b.name;
        });
        
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cin.ignore();
        vector<string> v;
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            v.push_back(s);
        }
        Solution ob;
        vector<alphanumeric> ans = ob.sortedStrings(N, v);
        for (auto u : ans) cout << u.name << " " << u.count << "\n";
    }
}
// } Driver Code Ends