//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        int res = 0;
        for(int i = 0 ; i < s.size() ; ++i) {
            vector<int> v(26, 0);
            v[s[i] - 'a']++;
            for(int j = i + 1 ; j < s.size() ; ++j) {
                v[s[j] - 'a']++;
                
                int minEl = INT_MAX, maxEl = INT_MIN;
                for(auto & el : v) {
                    if(el) {
                        minEl = min(minEl, el);
                        maxEl = max(maxEl, el);
                    }
                }
                
                res += maxEl - minEl;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends