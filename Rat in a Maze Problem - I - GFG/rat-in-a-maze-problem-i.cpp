//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int arr[4][2] = {{-1,0}, {0,-1}, {1,0}, {0, 1}};
    char dir[4] = {'U', 'L', 'D', 'R'};
    
    bool isValid(int x, int y, int n, vector<vector<int>>& m) {
        return !(x < 0 || y < 0 || x == n || y == n || m[x][y] == 0);
    }
    
    void solve(vector<vector<int>>& m, int n, vector<string>& res, string path, int x = 0, int y = 0) {
        if(x == n - 1 && y == n - 1) {
            res.push_back(path);
        }
        
        for(int i = 0 ; i < 4 ; i++) {
            int x1 = x + arr[i][0];
            int y1 = y + arr[i][1];
            if(isValid(x1, y1, n, m)) {
                m[x][y] = 0;
                path.push_back(dir[i]);
                solve(m, n, res, path, x1, y1);
                path.pop_back();
                m[x][y] = 1;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        if(m[0][0] == 0)    return res;
        m[0][0] = 1;
        string path;
        solve(m, n, res, path);
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends