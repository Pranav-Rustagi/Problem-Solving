//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k}); //x, y, currentLength, remaining k
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            
            int x = cur[0];
            int y = cur[1];
            
            if(x<0 || y<0 || x>=n || y>=m) continue; //edge case
            if(x == n-1 && y == m-1) return cur[2]; //reached to destination
            if(mat[x][y] == 1) //checking for obstacles
                if(cur[3] > 0) cur[3]--;
                else continue;
            if(vis[x][y] != -1 && vis[x][y] >= cur[3]) continue; //important case
            vis[x][y] = cur[3];
            
            q.push({x+1, y, cur[2]+1, cur[3]});
            q.push({x-1, y, cur[2]+1, cur[3]});
            q.push({x, y+1, cur[2]+1, cur[3]});
            q.push({x, y-1, cur[2]+1, cur[3]});
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends