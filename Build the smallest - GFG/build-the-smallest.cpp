//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    string res;
    for(int i = 0 ; i < num.size() ; ++i) {
        while(k && res.size() && res.back() > num[i]) {
            res.pop_back();
            k--;
        }
        res.push_back(num[i]);
    }
    
    while(k--)
        res.pop_back();
    int i = 0;
    while(i < res.size() - 1 && res[i] == '0')
        ++i;
    return res.substr(i);
}