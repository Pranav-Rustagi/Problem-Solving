//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Trie {
    public:
    Trie *arr[26];
    
    Trie() {
        for(int i = 0 ; i < 26 ; i++) {
            arr[i] = NULL;
        }
    }
    
    void insert(string& s) {
        Trie* cur = this;
        for(char ch : s) {
            if(cur -> arr[ch - 'a']) {
                cur = cur -> arr[ch - 'a'];
            } else {
                cur = cur -> arr[ch - 'a'] = new Trie();
            }
        }
    }
    
    bool search(string& s) {
        Trie* cur = this;
        for(char ch : s) {
            if(cur -> arr[ch - 'a'] == NULL) {
                return false;
            }
            cur = cur -> arr[ch - 'a'];
        }
        return true;
    }
};

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        Trie *t1 = new Trie(), *t2 = new Trie();
        for(string& s : s1) {
            t1 -> insert(s);
            reverse(s.begin(), s.end());
            t2 -> insert(s);
        }
        
        int res = 0;
        for(string& s : s2) {
            if(t1 -> search(s)) {
                res++;
            } else {
                reverse(s.begin(), s.end());
                res += t2 -> search(s);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends