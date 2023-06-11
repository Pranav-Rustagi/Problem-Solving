//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    bool solve(bool graph[101][101], int asmt[], int m, int n, int node = 0) {
        if(node == n) {
            return true;
        }
        
        for(int i = 1 ; i <= m ; i++) {
            bool ncontf = true;
            for(int j = 0 ; j < n ; j++) {
                if(node != j && graph[node][j] && asmt[j] == i) {
                    ncontf = false;
                    break;
                }
            }
            
            if(ncontf) {
                asmt[node] = i;
                if(solve(graph, asmt, m, n, node + 1)) {
                    return true;
                }
                asmt[node] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        int asmt[n] = {0};
        return solve(graph, asmt, m, n, 0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends