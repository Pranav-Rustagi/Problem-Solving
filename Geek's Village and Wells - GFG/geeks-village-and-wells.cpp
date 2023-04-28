//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool check(int i, int j, vector<vector<char>>& c, vector<vector<int>>& v, vector<vector<bool>>& vis) {
        if(i < 0 || i == c.size() || j < 0 || j == c[0].size() || c[i][j] == 'N' || vis[i][j]) {
            return false;
        }
        return true;
    }
    
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        vector<vector<int>> v(n, vector<int>(m, -1));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(c[i][j] == 'W') {
                    q.push({{ i, j }, 0});
                    vis[i][j] = true;
                }
            }
        }
        
        
        
        while(!q.empty()) {
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            int i1 = p.first.first, j1 = p.first.second, dis = p.second;
            vis[i1][j1] = true;
            v[i1][j1] = dis;
            dis += 2;
            if(check(i1 - 1, j1, c, v, vis)) {
                q.push({{ i1 - 1, j1 }, dis});
                vis[i1 - 1][j1] = true;
            }
            if(check(i1 + 1, j1, c, v, vis)) {
                q.push({{ i1 + 1, j1 }, dis});
                vis[i1 + 1][j1] = true;
            }
            if(check(i1, j1 - 1, c, v, vis)) {
                q.push({{ i1, j1 - 1 }, dis});
                vis[i1][j1 - 1] = true;
            }
            if(check(i1, j1 + 1, c, v, vis)) {
                q.push({{ i1, j1 + 1 }, dis});
                vis[i1][j1 + 1] = true;
            }
        }
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(c[i][j] != 'H') {
                    v[i][j] = 0;
                }
            }
        }
        
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends