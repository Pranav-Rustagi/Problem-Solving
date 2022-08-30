class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        for(int i = 0, lim = matrix.size() ; i < lim ; ++i)
            for(int j = 0 ; j < i ; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
    
    void reverseAll(vector<vector<int>>& matrix) {
        for(auto& v  : matrix)
            reverse(v.begin(), v.end());
    }
    
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverseAll(matrix);
    }
};