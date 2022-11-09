class StockSpanner {
public:
    stack<vector<int>> s;
    
    StockSpanner() {
    }
    
    int next(int price) {
        int ans = 1;
        while(!s.empty() && s.top()[0] <= price) {
            ans += s.top()[1];
            s.pop();
        }
        s.push({ price, ans });
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */