//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s) {
        stack<string> s1;
        stack<char> s2;
        s1.push("");
        for(char ch : s) { 
            if(ch >= '0' && ch <= '9') {
                s1.top().push_back(ch);
            } else {
                s2.push(ch);
                s1.push("");
            }
        }
        
        string res;
        while(!s1.empty()) {
            res += s1.top();
            s1.pop();
            if(!s2.empty()) {
                res.push_back(s2.top());
                s2.pop();
            }
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
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends