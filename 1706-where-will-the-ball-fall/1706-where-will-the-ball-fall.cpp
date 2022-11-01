class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> v(grid[0].size());
        iota(v.begin(), v.end(), 0);
        for(int row = 0 ; row < grid.size() ; ++row) {
            for(int b = 0 ; b < v.size() ; ++b) {
                if(v[b] == -1)
                    continue;
                if((grid[row][v[b]] == 1) && (v[b] + 1 < v.size() && grid[row][v[b] + 1] == 1))
                    ++v[b];
                else if((grid[row][v[b]] == -1) && (v[b] - 1 >= 0 && grid[row][v[b] - 1] == -1))
                    --v[b];
                else
                    v[b] = -1;
            }
        }
        
        return v;
    }
};