//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        map<int, pair<long long, long long>> mp;
        
        while(n--) {
            if(mp.count(arr[n])) {
                mp[arr[n]].first++;
            } 
            else {
                mp[arr[n]] = { 1, 0 };
            }
        }
        
        
        
        for(auto& p : mp) {
            auto iter = mp.find(p.first);
            if(iter == mp.begin())
                continue;
            --iter;
            p.second.second = (*iter).second.second;
            p.second.second += (*iter).first * (*iter).second.first;
        }
        
        vector<long long> res;
        for(int el : arr) {
            auto p = *mp.find(el);
            res.push_back(p.second.second);
        }
        return res; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends