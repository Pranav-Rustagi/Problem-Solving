//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int hopscotch(int n, int m, vector<vector<int>>& mat, int ty, int i, int j)
    {
        if(i < 0 || j < 0 || i == n || j == m)
            return 0;
        int sum = 0;
        mat[i][j] = 0;
        if(i > 0) {
            sum += mat[i - 1][j];
            mat[i - 1][j] = 0;
        }
        if(i < n - 1) {
            sum += mat[i + 1][j];
            mat[i + 1][j] = 0;
        }
        
        if(j > 0) {
            sum += mat[i][j - 1];
            mat[i][j - 1] = 0;
            
            if(j & 1) {
                if(i < n - 1) {
                    sum += mat[i + 1][j - 1];
                    mat[i + 1][j - 1] = 0;
                }
            } else {
                if(i > 0) {
                    sum += mat[i - 1][j - 1];
                    mat[i - 1][j - 1] = 0;
                }
            }
        }
        if(j < m - 1) {
            sum += mat[i][j + 1];
            mat[i][j + 1] = 0;
            if(j & 1) {
                if(i < n - 1) {
                    sum += mat[i + 1][j + 1];
                    mat[i + 1][j + 1] = 0;
                }
            } else {
                if(i > 0) {
                    sum += mat[i - 1][j + 1];
                    mat[i - 1][j + 1] = 0;
                }
            }
        }
        
        if(ty == 1) {
            int sum2 = 0;
            sum2 += hopscotch(n, m, mat, ty - 1, i - 1, j);
            sum2 += hopscotch(n, m, mat, ty - 1, i + 1, j);
            sum2 += hopscotch(n, m, mat, ty - 1, i, j - 1);
            sum2 += hopscotch(n, m, mat, ty - 1, i, j + 1);
            if(j & 1) {
                sum2 += hopscotch(n, m, mat, ty - 1, i + 1, j - 1);
                sum2 += hopscotch(n, m, mat, ty - 1, i + 1, j + 1);
            }
            else {
                sum2 += hopscotch(n, m, mat, ty - 1, i - 1, j - 1);
                sum2 += hopscotch(n, m, mat, ty - 1, i - 1, j + 1);
            }
            return sum2;
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends