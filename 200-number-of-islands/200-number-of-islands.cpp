class Solution {
public:
    int count = 0;
    
    void erase(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        erase(grid, i - 1, j);
        erase(grid, i + 1, j);
        erase(grid, i, j - 1);
        erase(grid, i, j + 1);
    }
    
    int numIslands(vector<vector<char>>& grid, int i = 0, int j = 0) {
        for(int i = 0 ; i < grid.size() ; ++i) {
            for(int j = 0 ; j < grid[0].size() ; ++j) {
                if(grid[i][j] == '1') {
                    ++count;
                    erase(grid, i , j);
                }
            }
        }
        
        return count;
    }
};