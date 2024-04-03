#define vvc vector<vector<char>> 

class Solution {
public:
    bool solve(vvc& board, string& word, int m, int n, int sz, int i, int j, int ind = 0) {
        // cout << i << " " << j << " " << ind << "\n";
        if(ind == sz)   return true;
        if(i < 0 || j < 0 || i == m || j == n || board[i][j] != word[ind])  return false;
        // if(dp[i][j][ind] != -1) return dp[i][j][ind];
        
        board[i][j] = '#';
        int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        
        for(int l = 0 ; l < 4 ; l++) {
            int x = i + dir[l][0], y = j + dir[l][1];
            
            if(solve(board, word, m, n, sz, x, y, ind + 1)) {
                return true;
            }
        }
        
        board[i][j] = word[ind];
        return false;
    }
    
    bool exist(vvc& board, string word) {
        int m = board.size(), n = board[0].size(), sz= word.size();
        
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(solve(board, word, m, n, sz, i, j)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};