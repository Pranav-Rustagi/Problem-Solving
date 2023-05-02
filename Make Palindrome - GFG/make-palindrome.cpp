//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        unordered_set<string> set;
        for(string s : arr) {
            string t = s;
            reverse(t.begin(), t.end());
            if(set.count(t)) {
                set.erase(t);
            } else { 
                set.insert(s);
            }
        }
        
        if(set.size() == 0) {
            return true;
        }
        
        if(set.size() > 1) {
            return false;
        }
        
        string temp = *set.begin();
        int i = 0, j = temp.size() - 1;
        while(i < j) {
            if(temp[i++] != temp[j--]) {
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends