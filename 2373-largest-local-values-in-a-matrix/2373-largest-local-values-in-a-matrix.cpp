class Solution {
public:
    int getmaxval(int x, int y, vector<vector<int>>& grid) {
        int res = 0;
        int dir[9][2] = {{-1,-1}, {-1, 0}, {-1, 1},{0,-1}, {0, 0}, {0, 1},{1,-1}, {1, 0}, {1, 1}};
        
        for(int i = 0 ; i < 9 ; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            
            res = max(res, grid[tx][ty]);
        }
        
        return res;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2));
        
        for(int i = 0 ; i < n - 2 ; i++) {
            for(int j = 0 ; j < n - 2 ; j++) {
                res[i][j] = getmaxval(i + 1, j + 1, grid);
            }
        }
        
        return res;
    }
};