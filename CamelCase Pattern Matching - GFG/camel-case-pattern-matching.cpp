//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> D, string P) {
        sort(D.begin(), D.end());
        vector<string> v;
        
        for(string& s : D) {
            bool add = true;
            int i = 0, j = 0;
            while(j < s.size() && s[j] > 'Z') {
                j++;
            }
                
            while(i < P.size() && j < s.size()) {
                if(P[i++] != s[j++]) {
                    add = false;
                    break;
                }
                
                while(j < s.size() && s[j] > 'Z') {
                    j++;
                }
            }
            if(i == P.size() && add) {
                v.push_back(s);
            }
        }
        
        if(v.size() == 0) {
            v.push_back("-1");
        }
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
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends