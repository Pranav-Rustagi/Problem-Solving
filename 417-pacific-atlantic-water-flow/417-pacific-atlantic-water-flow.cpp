class Solution {
public:
    vector<vector<int>> v;
    
    void solve(vector<vector<int>>& h, int i, int j, bool& isP, bool& isA, int prev) {
        if(isP && isA)
            return;
        
        if(i < 0 || j < 0) {
            isP = true;
            return;
        }
        
        if(i == h.size() || j == h[0].size()) {
            isA = true;
            return;
        }
        
        if(prev < h[i][j])
            return;
        
        int temp = h[i][j];
        h[i][j] = INT_MAX;
        solve(h, i - 1, j, isP, isA, temp);
        solve(h, i + 1, j, isP, isA, temp);
        solve(h, i, j - 1, isP, isA, temp);
        solve(h, i, j + 1, isP, isA, temp);
        h[i][j] = temp;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        for(int i = 0 ; i < heights.size() ; ++i) {
            for(int j = 0 ; j < heights[0].size() ; ++j) {
                bool isA = false, isP = false;
                solve(heights, i, j, isP, isA, INT_MAX);
                if(isP && isA)
                    v.push_back({i, j});
            }
        }
        
        return v;
    }
};