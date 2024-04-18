class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 0) {
                    continue;
                }
                
                res += (i == 0 || grid[i - 1][j] == 0);
                res += (i == m - 1 || grid[i + 1][j] == 0);
                res += (j == 0 || grid[i][j - 1] == 0);
                res += (j == n - 1 || grid[i][j + 1] == 0);
            }
        }

        return res;
    }
};