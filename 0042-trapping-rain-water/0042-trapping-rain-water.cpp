class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> rtl(height);
        
        int n = height.size();
        
        for(int i = n - 2 ; i >= 0 ; i--) {
            rtl[i] = max(rtl[i], rtl[i + 1]);
        }
        
        int ltr = 0, res = 0;
        for(int i = 0 ; i < n ; i++) {
            ltr = max(ltr, height[i]);
            
            res += min(ltr, rtl[i]) - height[i];
        }
        
        return res;
    }
};