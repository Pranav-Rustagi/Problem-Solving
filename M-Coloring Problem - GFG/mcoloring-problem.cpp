//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<int> placed;
    
    bool solve(bool graph[101][101], int n, int m, int ind = 0) {
        if(ind == n) {
            return true;
        }
        
        for(int i = 0 ; i < m ; i++) {
            placed[ind] = n + i;
            bool isValid = true;
            for(int j = 0 ; j < n ; j++) {
                if(ind != j && (graph[ind][j] || graph[j][ind]) && placed[j] == n + i) {
                    isValid = false;
                    break;
                }
            }
            
            if(isValid && solve(graph, n, m, ind + 1)) {
                return true;
            }
            placed[ind] = -1;
        }
        
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        placed.resize(n, -1);
        return solve(graph, n, m);
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