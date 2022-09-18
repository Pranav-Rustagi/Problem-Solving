class Solution {
public:
    int trap(vector<int>& h1) {
        vector<int> h2(h1);
        
        for(int i = 0, maxH = INT_MIN ; i < h1.size() ; ++i) {
            if(h1[i] > maxH)
                maxH = h1[i];
            h1[i] = maxH - h1[i];
        }
        
        for(int i = h2.size() - 1, maxH = INT_MIN ; i >= 0 ; --i) {
            if(h2[i] > maxH)
                maxH = h2[i];
            h2[i] = maxH - h2[i];
        }
        
        int res = 0;
        for(int i = 0 ; i < h1.size() ; ++i)
            res += min(h1[i], h2[i]);
        return res;
    }
};