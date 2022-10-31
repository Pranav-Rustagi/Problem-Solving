class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size() - 1, col = 0;
        while(col < matrix[0].size()) {
            int tr = row + 1, tc = col + 1;
            while(tr < matrix.size() && tc < matrix[0].size()) {
                if(matrix[tr][tc] != matrix[row][col])
                    return false;
                ++tr;
                ++tc;
            }
            
            if(row > 0)
                --row;
            else
                ++col;
        }
        
        return true;
    }
};