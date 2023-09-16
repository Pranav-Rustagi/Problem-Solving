class Solution {
public:
    bool check(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int vals[m][n];
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                vals[i][j] = INT_MAX;
            }
        }

        vals[0][0] = 0;
        queue<pair<int, int>> q;
        q.push({ 0, 0 });

        int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for(int i = 0 ; i < 4 ; i++) {
                int x = p.first + dir[i][0];
                int y = p.second + dir[i][1];

                if(!check(x, y, m, n))  continue;

                int newdiff = abs(heights[p.first][p.second] - heights[x][y]);
                int newVal = max(vals[p.first][p.second], newdiff);
                if(newVal < vals[x][y]) {
                    vals[x][y] = newVal;
                    q.push({ x, y });
                }
            }
        }

        return vals[m - 1][n - 1];
    }
};