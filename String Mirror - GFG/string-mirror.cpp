//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        int i = 1;
        while(i < str.size() && str[i - 1] > str[i]) { i++; }
        while(i > 1 && i < str.size() && str[i - 1] >= str[i]) { i++; }
        
        string temp = str.substr(0, i);
        string temp2 = temp;
        reverse(temp2.begin(), temp2.end());
        return temp + temp2;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends