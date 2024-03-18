class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>> resv;
        sort(points.begin(), points.end());
        
        for(auto p : points) {
            if(resv.empty() || resv.back()[1] < p[0]) {
                resv.push_back(p);
            } else {
                resv.back()[1] = min(resv.back()[1], p[1]);
            }
        }
        
        return resv.size();
    }
};