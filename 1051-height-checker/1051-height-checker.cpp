class Solution {
public:
    int heightChecker(vector<int>& heights) {
        multiset<int> temp(heights.begin(), heights.end());
        int ind = 0, res = 0;
        
        for(auto el : temp) {
            if(el != heights[ind++]) {
                res++;
            }
        }
        
        return res;
    }
};