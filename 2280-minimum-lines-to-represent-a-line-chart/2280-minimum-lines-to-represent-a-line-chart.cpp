class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if(stockPrices.size() == 1)
            return 0;
        sort(stockPrices.begin(), stockPrices.end());
        
        int res = 1;
        long long dy = (stockPrices[1][1] - stockPrices[0][1]), dx = (stockPrices[1][0] - stockPrices[0][0]);
        
        for(int i = 2 ; i < stockPrices.size() ; ++i) {
            long long ty = (stockPrices[i][1] - stockPrices[i - 1][1]);
            long long tx = (stockPrices[i][0] - stockPrices[i - 1][0]);
            
            if(dy * tx != ty * dx) {
                ++res;
                dy = ty;
                dx = tx;
            }
        }
        
        return res;
    }
};