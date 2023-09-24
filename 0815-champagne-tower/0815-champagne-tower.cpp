class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double res[100][100] = {0};
        res[0][0] = poured;

        for(int i = 0 ; i < query_row ; i++) {
            for(int j = 0 ; j <= i ; j++) {
                if(res[i][j] > 1) {
                    double extra = (res[i][j] - 1) / 2;
                    res[i + 1][j] += extra;
                    res[i + 1][j + 1] += extra;
                } 
            }
        }

        return min(1.0, res[query_row][query_glass]);
    }
};