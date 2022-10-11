//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        vector<int> c;
        vector<string> w;
        string res;
        
        s = "1[" + s + "]";
        
        for(int i = 0 ; i < s.size() ; ++i) {
            if(s[i] >= '0' && s[i] <= '9') {
                if(i == 0 || (s[i - 1] >= 'a' && s[i - 1] <= 'z') || (s[i - 1] == ']'))
                    c.push_back(s[i] - '0');
                else if(s[i - 1] == '[') {
                    w.push_back("");
                    c.push_back(s[i] - '0');
                }
                else
                    c.back() = c.back() * 10 + s[i] - '0';
            }
            else if(s[i] >= 'a' && s[i] <= 'z') {
                if(s[i - 1] == '[')
                    w.push_back("");
                w.back().push_back(s[i]);
            }
            else if(s[i] == ']') {
                res = "";
                int count = c.back();
                c.pop_back();
                string word = w.back();
                w.pop_back();
                while(count--) {
                    res += word;
                }
                
                if(w.size())
                    w.back() += res;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends