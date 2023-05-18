//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void mark(int i, int j, int N, int M, vector<vector<int>>& g) {
        if(i < 0 || i == N || j < 0 || j == M || g[i][j] == 0) {
            return;
        }
        g[i][j] = 0;
        mark(i - 1, j, N, M, g);
        mark(i + 1, j, N, M, g);
        mark(i, j - 1, N, M, g);
        mark(i, j + 1, N, M, g);
    }
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        for(int i = 0 ; i < N ; i++) {
            mark(i, 0, N, M, matrix);
            mark(i, M - 1, N, M, matrix);
        }
        
        for(int j = 1 ; j < M - 1 ; j++) {
            mark(0, j, N, M, matrix);
            mark(N - 1, j, N, M, matrix);
        }
        
        int res = 0;
        for(int i = 1 ; i < N - 1 ; i++) {
            for(int j = 1 ; j < M - 1 ; j++) {
                if(matrix[i][j] == 1) {
                    res++;
                    mark(i, j, N, M, matrix);
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends