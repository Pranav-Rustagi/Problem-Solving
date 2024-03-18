class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int, int>> resv;
        sort(points.begin(), points.end());
        int count = 0;
        
        for(auto& p : points) {
            if(resv.empty() || resv.back().second < p[0]) {
                resv.push_back({p[0], p[1]});
                count++;
            } else if (resv.back().second > p[1]) {
                resv.back().second = p[1];
            }
        }
        
        return count;
    }
};