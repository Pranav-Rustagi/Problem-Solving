class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<vector<int>> v;
        for(int i = 0 ; i < plantTime.size() ; ++i) {
            v.push_back({ plantTime[i], growTime[i] });
        }
        
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        
        
        int res = v[0][0] + v[0][1];
        for(int i = 1 ; i < v.size() ; ++i) {
            v[i][0] += v[i - 1][0];
            res = max(res, v[i][0] + v[i][1]);
        }
        
        return res;
    }
};